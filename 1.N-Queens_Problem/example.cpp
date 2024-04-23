#include "user_propagator.h"
#include "user_propagator_with_theory.h"

/**
 * The program solves the n-queens problem (number of solutions) with 4 different approaches
 * 1) Bit-Vector constraints + Default solver + Blocking Clauses
 * 2) Bit-Vector constraints + Simple solver + Blocking Clauses
 * 3) Bit-Vector constraints + Simple solver + Adding contradictions in the propagator
 * 4) Constraints only implicit via the propagator + Simple solver + Adding contradictions in the propagator
 *
 * Runs 1 + 2 are done for comparison with 3 + 4
 */

using namespace std::chrono;

#define REPETITIONS 5

#define MIN_BOARD 4
#define MAX_BOARD1 12
#define MAX_BOARD2 12

/**
 * 创建表示皇后的 Z3 表达式向量 queens：
 * context：为上下文对象
 * num：为变量数
 * bits：位向量宽度（位向量形式）
 * prefix：变量前缀（默认为空）
 * 注：每个变量实际存储的是皇后在棋盘中的列标
 */
z3::expr_vector createQueens(z3::context &context, unsigned num, int bits, std::string prefix) {
    z3::expr_vector queens(context);
    for (unsigned i = 0; i < num; i++) {
        queens.push_back(context.bv_const((prefix + "q" + to_string(i)).c_str(), bits));
    }
    return queens;
}

/**
 * 创建表示皇后向量的 Z3 表达式向量：
 * contex：上下文对象
 * num：变量数
 */
z3::expr_vector createQueens(z3::context &context, unsigned num) {
    return createQueens(context, num, log2i(num) + 1, "");  // 位向量变量的位宽为变量数取对数
}

/**
 * 创建约束：
 * context：上下文对象
 * queens：变量表达式向量
 */
z3::expr createConstraints(z3::context &context, const z3::expr_vector &queens) {
    z3::expr_vector assertions(context);

    // 约束列序号的范围
    for (unsigned i = 0; i < queens.size(); i++) {
        // assert column range
        assertions.push_back(z3::uge(queens[i], 0));
        assertions.push_back(z3::ule(queens[i], (int)(queens.size() - 1)));
    }

    // 约束每个变量不能重复
    z3::expr_vector distinct(context);
    for (const z3::expr &queen : queens) {
        distinct.push_back(queen);
    }
    assertions.push_back(z3::distinct(distinct));

    // 约束皇后不能出现在同一对角线
    for (unsigned i = 0; i < queens.size(); i++) {
        for (unsigned j = i + 1; j < queens.size(); j++) {
            assertions.push_back((int)(j - i) != (queens[j] - queens[i]));
            assertions.push_back((int)(j - i) != (queens[i] - queens[j]));
        }
    }

    return z3::mk_and(assertions);  // 以上约束合取即为n-皇后问题的约束
}

/**
 * 测试方法 0/1：
 * num：变量数
 * simple：是否使用 Simple solver
 * 返回模型数量
 */
int test01(unsigned num, bool simple) {
    z3::context context;
    z3::solver solver(context, !simple ? Z3_mk_solver(context) : Z3_mk_simple_solver(context));  // 选择是否使用 Sample Solver

    z3::expr_vector queens = createQueens(context, num);  // 创建皇后变量

    solver.add(createConstraints(context, queens));  // 添加约束

    int solutionId = 1;  // 记录所得解的序号

    while (true) {
        z3::check_result res = solver.check();  // 求解

        if (res != z3::check_result::sat) {  // 若无法得到新的解，结束求解过程
            break;
        }

        z3::model model = solver.get_model();  // 获取所得模型

        WriteLine("Model #" + to_string(solutionId) + ":");  // 打印模型序号
        solutionId++;

        z3::expr_vector blocking(context);  // 创建阻塞约束集合（阻塞子句）

        for (unsigned i = 0; i < num; i++) {  // 评估模型中的所有变量取值
            z3::expr eval = model.eval(queens[i]);
            WriteLine(("q" + to_string(i) + " = " + to_string(eval.get_numeral_int())));
            blocking.push_back(queens[i] != eval);  // 阻塞该变量取值
        }

        solver.add(z3::mk_or(blocking));  // 阻塞约束之间为或关系

        WriteEmptyLine;
    }
    return solutionId - 1;
}

/* Default solver + Blocking Clause */
inline int test0(unsigned num) {
    return test01(num, false);
}

/* Simple solver + Blocking Clause */
inline int test1(unsigned num) {
    return test01(num, true);
}

/**
 * 测试方法 2/3：
 * num：变量数
 * withTheory：是否使用自定义理论
 * 返回模型数
 */
int test23(unsigned num, bool withTheory) {
    z3::context context;
    z3::solver solver(context, z3::solver::simple());  // 默认使用 Simple solver
    std::unordered_map<z3::expr, unsigned> idMapping;  // 将 Z3 表达式映射到 ID（用于存储行号）

    user_propagator *propagator;  // 传播器指针
    if (!withTheory) {
        propagator = new user_propagator(&solver, idMapping, num);  // 使用不带理论的用户传播器
    } else {
        propagator = new user_propagator_with_theory(&solver, idMapping, num);  // 使用带理论的用户传播器
    }

    z3::expr_vector queens = createQueens(context, num);  // 创建皇后变量

    for (unsigned i = 0; i < queens.size(); i++) {  // 遍历变量列表
        propagator->add(queens[i]);                 // 将皇后变量注册到用户传播器
        idMapping[queens[i]] = i;                   // 记录变量映射到皇后所在的行号（ID）
    }

    if (!withTheory) {                                   // 若使用不带自定义理论的用户传播器
        solver.add(createConstraints(context, queens));  // 加入位向量约束
    }
    /* 若使用带自定义理论的用户传播器，则求解器会在 fixed 阶段检查变量取值是否合法 */
    solver.check();
    int res = propagator->getModelCount();  // 计算模型数
    delete propagator;
    return res;  // 返回模型数
}

/* Bit-Vector constraints + Simple solver + Adding constraints in the propagator */
inline int test2(unsigned num) {
    return test23(num, false);
}

/* Constraints only implicit via the propagator + Simple solver + Adding constraints in the propagator */
inline int test3(unsigned num) {
    return test23(num, true);
}

int main() {
    /* 问题规模由 MIN_BOARD 扩展到 MAX_BOARD1 */
    for (int num = MIN_BOARD; num <= MAX_BOARD1; num++) {
        std::cout << "num = " << num << ":\n"
                  << std::endl;

        unsigned seed = (unsigned)high_resolution_clock::now().time_since_epoch().count();  // 生成一个基于当前时间的随机种子
        const char *testName[] =
            {
                "BV + Blocking clauses (Default solver)",
                "BV + Blocking clauses (Simple solver)",
                "BV + Adding conflicts",
                "Custom theory + conflicts",
            };
        /* 每种变体的序号 */
        int permutation[4] = {
            0,
            1,
            2,
            3,
        };
        double timeResults[REPETITIONS * SIZE(permutation)];  // 用于存储时间

        for (int rep = 0; rep < REPETITIONS; rep++) {  // 重复次数
            // Execute strategies in a randomised order
            std::shuffle(&permutation[0], &permutation[SIZE(permutation) - 1], std::default_random_engine(seed));  // 随机打乱 permutation 中的元素顺序

            for (int i : permutation) {  // 执行四种策略
                int modelCount = -1;     // 统计模型数

                auto now1 = high_resolution_clock::now();  // 获取当前时间

                // model counting ?
                switch (i) {
                    case 0:
                        modelCount = test0(num);
                        break;
                    case 1:
                        modelCount = test1(num);
                        break;
                    case 2:
                        modelCount = test2(num);
                        break;
                    case 3:
                        modelCount = test3(num);
                        break;
                    default:
                        WriteLine("Unknown case");
                        break;
                }
                auto now2 = high_resolution_clock::now();
                duration<double, std::milli> ms = now2 - now1;  // 记录求解花费的时间
                std::cout << testName[i] << " took " << ms.count() << "ms (" << modelCount << " models)" << std::endl;
                timeResults[rep * SIZE(permutation) + i] = ms.count();
                WriteLine("-------------");
            }
        }

        std::cout << "\n"
                  << std::endl;

        for (unsigned i = 0; i < SIZE(permutation); i++) {  // 遍历所有变体
            std::cout << testName[i];
            double sum = 0;
            for (int j = 0; j < REPETITIONS; j++) { // 输出变体每轮执行的时间
                std::cout << " " << timeResults[j * SIZE(permutation) + i] << "ms";
                sum += timeResults[j * SIZE(permutation) + i];
            }
            std::cout << " | avg: " << sum / REPETITIONS << "ms" << std::endl; // 输出变体方法执行的平均时间
        }

        std::cout << std::endl;
    }
}