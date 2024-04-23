#ifndef USER_PROPAGATOR_H
#define USER_PROPAGATOR_H

#include "common.h"

class user_propagator : public z3::user_propagator_base {
 private:
  simple_model currentModel;                          // 当前模型（理论原子的逻辑赋值）
  std::unordered_set<simple_model> modelSet;          // 模型集
  z3::expr_vector fixedValues;                        // 固定变量集
  std::stack<int> fixedCnt;                           // 用于锚定某一时刻已决策的变量数
  std::unordered_map<z3::expr, int> expr2Int;         // 理论原子到布尔变量的映射
  int solutionNr = 1;                                 // 所得解的序号
  z3::solver* external_solver;

  /* for randomness */
  std::random_device rd;
  std::mt19937 gen{rd()};

 public:
  /* 获取模型数 */
  int getModelCount() const {
    return solutionNr - 1;
  }

  /* 最终事件处理器 */
  void final() override {
    this->conflict(fixedValues);                          // 向传播器中添加约束，阻塞当前模型
    if (modelSet.find(currentModel) != modelSet.end()) {      // 若该模型已经存在
      return;
    }
    solutionNr++;  // 统计模型数
#ifdef VERBOSE
    for (unsigned i = 0; i < fixedValues.size(); i++) {
        z3::expr fixed = fixedValues[i];
        WriteLine("q" + to_string(queenToY[fixed]) + " = " + to_string(currentModel[queenToY[fixed]]));
    }
#endif
    modelSet.insert(currentModel);  // 将当前模型加入模型集
  }

  void fixed(z3::expr const &ast, z3::expr const &value) override{
    unsigned var = expr2Int[ast];
    bool val = value.bool_value();

    for (auto fixed : fixedValues){
      z3::expr_vector conflicting(ast.ctx());

    }

    fixedValues.push_back(ast);
    std::cout << value.to_string() << std::endl;
    currentModel[var] = val;
  }

  /**
   * val：正在被决策的变量
   * bits：表示哪个位正在被决策
   * is_pos：为决策变量赋何值
   * */
  void decide(z3::expr const& val, unsigned bits, bool is_pos) override {
    std::uniform_int_distribution<int> dist(0, 99);
    int random_val = dist(gen);
    if (random_val % 2 == 0)
      is_pos = true;
    else
      is_pos = false;
    add(val == is_pos);
  }

  /* 基于上下文对象创建用户传播器 */
  // user_propagator(z3::context &c)
  //     : user_propagator_base(c), fixedValues(c) {
  //   this->register_fixed();  // 注册固定事件处理器
  //   this->register_decide();
  //   this->register_final();  // 注册最终事件处理器
  // }

  /* 基于求解器创建用户传播器 */
  user_propagator(z3::solver *s, z3::solver *_s, std::unordered_map<z3::expr, unsigned> &v2i)
      : user_propagator_base(s), fixedValues(s->ctx()), external_solver(_s) {
    this->register_fixed();
    this->register_decide();
    this->register_final();
  }

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
        currentModel[expr2Int[fixedValues[j - 1]]] = (unsigned)-1;  // 将最近一次 push 后的变量赋值还原
      }
      fixedValues.resize(lastCnt);
    }
  }

  ~user_propagator() = default;

  user_propagator_base *fresh(z3::context &) override {
    return this;
  }
};

#endif