#pragma once

#include "user_propagator.h"

/* 带有理论的用户自定义传播器 */
class user_propagator_with_theory : public user_propagator {
   public:
    user_propagator_with_theory(z3::context &c, std::unordered_map<z3::expr, unsigned> &idMapping, unsigned board)
        : user_propagator(c, idMapping, board) {}

    user_propagator_with_theory(z3::solver *s, std::unordered_map<z3::expr, unsigned> &idMapping, unsigned board)
        : user_propagator(s, idMapping, board) {}

    /**
     *  固定事件处理器：
     *  将 ast 固定为 value
     * */
    void fixed(z3::expr const &ast, z3::expr const &value) override {
        unsigned queenId = queenToY[ast];    // 获取当前变量的行号
        unsigned queenPos = bvToInt(value);  // 获取当前变量在该行的位置（列标）

        if (queenPos >= board) {                     // 检查列标是否越界
            z3::expr_vector conflicting(ast.ctx());  // 创建冲突向量
            conflicting.push_back(ast);              // 存储当前变量
            this->conflict(conflicting);             // 调用冲突事件处理器
            return;
        }

        /* 遍历之前固定的所有皇后 */
        for (const z3::expr &fixed : fixedValues) {
            unsigned otherId = queenToY[fixed];                 // 变量行号
            unsigned otherPos = currentModel[queenToY[fixed]];  // 变量列号

            if (queenPos == otherPos) {  // 若出现列冲突
                z3::expr_vector conflicting(ast.ctx());
                conflicting.push_back(ast);  // 保存冲突变量
                conflicting.push_back(fixed);
                this->conflict(conflicting);  // 调用冲突事件处理器
                continue;
            }
            int diffY = abs((int)queenId - (int)otherId);
            int diffX = abs((int)queenPos - (int)otherPos);
            if (diffX == diffY) {  // 若皇后出现在同一对角线
                z3::expr_vector conflicting(ast.ctx());
                conflicting.push_back(ast);
                conflicting.push_back(fixed);
                this->conflict(conflicting);
            }
        }

        fixedValues.push_back(ast);              // 将 ast 存入已被固定的变量集
        currentModel[queenToY[ast]] = queenPos;  // 将 行标->列标 的映射存入当前模型
    }
};