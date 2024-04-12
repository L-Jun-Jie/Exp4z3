#pragma once

#include "common.h"

/* 自定义用户传播器 */
class user_propagator : public z3::user_propagator_base {
   protected:
    unsigned board;  // 边界（棋盘的列数？？）
    std::unordered_map<z3::expr, unsigned> &queenToY;
    simple_model currentModel;                  // 当前模型（无符号整形数组）
    std::unordered_set<simple_model> modelSet;  // 模型集合
    z3::expr_vector fixedValues;                // 固定值
    std::stack<unsigned> fixedCnt;              // 固定变量数

    int solutionNr = 1;  // 解的序号

   public:
    /* 获取模型数 */
    int getModelCount() const {
        return solutionNr - 1;
    }

    /* 最终事件处理器 */
    void final() override {
        this->conflict(fixedValues);                          // 向传播器中添加约束，阻塞当前模型
        if (modelSet.find(currentModel) != modelSet.end()) {  // 若该模型已经存在
            WriteLine("Got already computed model");
            return;
        }
        Write("Model #" << solutionNr << ":\n");
        solutionNr++;  // 统计模型数
#ifdef VERBOSE
        for (unsigned i = 0; i < fixedValues.size(); i++) {
            z3::expr fixed = fixedValues[i];
            WriteLine("q" + to_string(queenToY[fixed]) + " = " + to_string(currentModel[queenToY[fixed]]));
        }
#endif
        modelSet.insert(currentModel);  // 将当前模型加入模型集
        WriteEmptyLine;
    }

    static unsigned bvToInt(z3::expr const &e) {
        return (unsigned)e.get_numeral_int();
    }

    /* 固定事件处理器 */
    void fixed(z3::expr const &ast, z3::expr const &value) override {
        fixedValues.push_back(ast);             // 将 ast 存入已固定变量集
        unsigned valueBv = bvToInt(value);      // 计算当前变量的取值
        currentModel[queenToY[ast]] = valueBv;  // 将变量到其取值的映射加入当前模型
    }

    /* 基于上下文对象创建用户传播器 */
    user_propagator(z3::context &c, std::unordered_map<z3::expr, unsigned> &queenToY, unsigned board)
        : user_propagator_base(c), board(board), queenToY(queenToY), fixedValues(c), currentModel(board, (unsigned)-1) {
        this->register_fixed();  // 注册固定事件处理器
        this->register_final();  // 注册最终事件处理器
    }

    /* 基于求解器创建用户传播器 */
    user_propagator(z3::solver *s, std::unordered_map<z3::expr, unsigned> &idMapping, unsigned board)
        : user_propagator_base(s), board(board), queenToY(idMapping), fixedValues(s->ctx()), currentModel(board, (unsigned)-1) {
        this->register_fixed();
        this->register_final();
    }

    ~user_propagator() = default;

    /* 将当前固定变量数压栈（标记锚点） */
    void push() override {
        fixedCnt.push((unsigned)fixedValues.size());
    }

    /* 变量赋值回溯到最近一次 push 前的状态 */
    void pop(unsigned num_scopes) override {
        for (unsigned i = 0; i < num_scopes; i++) {
            unsigned lastCnt = fixedCnt.top();  // 获取最近固定的变量数
            fixedCnt.pop();                     // 回溯
            // Remove fixed values from model
            for (unsigned j = fixedValues.size(); j > lastCnt; j--) {
                currentModel[queenToY[fixedValues[j - 1]]] = (unsigned)-1;  // 将最近一次 push 后的变量赋值还原
            }
            fixedValues.resize(lastCnt);
        }
    }

    user_propagator_base *fresh(z3::context &) override {
        return this;
    }
};