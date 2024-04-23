#ifndef USER_PROPAGATOR_H
#define USER_PROPAGATOR_H

#include <z3++.h>

#include "common.h"

class user_propagator : public z3::user_propagator_base {
   protected:
    z3::expr_vector m_trail;                           // 当前固定值
    std::stack<unsigned> fixedCnt;                     // 记录回溯点
    int solutionNr = 1;                                // 解的序号
    simple_model currentModel;                         // 当前模型（无符号整形数组）
    std::unordered_set<simple_model> modelSet;         // 模型集合
    std::unordered_map<z3::expr, unsigned>& varToInt;  // 变量到整数的映射

   public:
    int getModelCount() const {
        return solutionNr - 1;
    }
    user_propagator(z3::context& c, std::unordered_map<z3::expr, unsigned>& varToInt, unsigned var_num)
        : user_propagator_base(c), varToInt(varToInt), m_trail(c), currentModel(var_num, -1) {
        this->register_fixed();  // 注册固定事件处理器
        this->register_final();  // 注册最终事件处理器
    }
    user_propagator(z3::solver* s, std::unordered_map<z3::expr, unsigned>& varToInt, unsigned var_num)
        : user_propagator_base(s), varToInt(varToInt), m_trail(s->ctx()), currentModel(var_num, -1) {
        this->register_fixed();  // 注册固定事件处理器
        this->register_final();  // 注册最终事件处理器
    }

    ~user_propagator() = default;

    void push() override {
        fixedCnt.push((unsigned)m_trail.size());  // 标记回溯点
    }

    void pop(unsigned num_scopes) override {
        for (unsigned i = 0; i < num_scopes; ++i) {
            unsigned lastCnt = fixedCnt.top();  // 获取回溯点
            fixedCnt.pop();                     // 弹出回溯点
            for (unsigned j = m_trail.size(); j > lastCnt; --j) {
                currentModel[varToInt[m_trail[j - 1]]] = -1;
                std::cout << "Unassign the variable " << m_trail[j - 1].decl().name() << std::endl;
            }
            m_trail.resize(lastCnt);
        }
    }

    void fixed(z3::expr const& ast, z3::expr const& value) override {
        m_trail.push_back(ast);
        assert(value.is_bool());
        bool valueBool = value.bool_value() == Z3_L_TRUE ? true : false;

        std::cout <<  "Fixed variable " << ast.decl().name() << " as " << valueBool << std::endl;

        assert(valueBool == 1 || valueBool == 0);
        currentModel[varToInt[ast]] = valueBool;
    }

    void final() override {
        this->conflict(m_trail);
        if (modelSet.find(currentModel) != modelSet.end()) {  // 若该模型已经存在
            return;
        }
        std::cout << "The " << solutionNr << " model is as follows: " << std::endl;
        for (unsigned i = 0; i < m_trail.size(); i++) {
            z3::expr fixed = m_trail[i];
            std::cout << "q" << to_string(varToInt[fixed]) + " = " + to_string(currentModel[varToInt[fixed]]) << std::endl;
        }
        std::cout << std::endl;
        solutionNr++;
        modelSet.insert(currentModel);  // 将当前模型加入模型集
    }

    user_propagator_base* fresh(z3::context&) override {
        return this;
    }
};

#endif