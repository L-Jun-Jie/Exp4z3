#include <z3++.h>

#include <iostream>
#include <unordered_map>
#include "common.h"

using namespace std;

int idx = 0;

// 将理论原子转换为布尔变量 expr --> expr
z3::expr abstract_atom(z3::context& c, unordered_map<z3::expr, z3::expr>& abs, const z3::expr& atom) {
    auto it = abs.find(atom);
    if (it != abs.end()) {
        z3::expr p = it->second;
        return p;
    }
    string var_name = ("p" + to_string(idx++));

    // 使用 map[] 令类作为对象时，需要保证该类有无参构造
    auto pair = std::make_pair(atom, c.bool_const(var_name.c_str()));
    abs.insert(pair);
    return pair.second;
}

// 将文字进行抽象化
z3::expr abstract_lit(z3::context& c, unordered_map<z3::expr, z3::expr>& abs, const z3::expr& lit) {
    if (lit.is_not())                                           // 若为负文字
        return !abstract_atom(c, abs, lit.arg(0));  // 将其对应变量进行抽象
    return abstract_atom(c, abs, lit);
}

// 将一个子句中的文字进行抽象
z3::expr abstract_clause(z3::context& c, unordered_map<z3::expr, z3::expr>& abs, const z3::expr_vector& clause) {
    z3::expr_vector res(c);
    for (unsigned i = 0; i < clause.size(); ++i) {
        res.push_back(abstract_lit(c, abs, clause[i]));
    }
    return mk_or(res);  // 同一子句中文字的关系为析取
}

// 将所有子句进行抽象
z3::expr_vector abstract_clauses(z3::context& c, unordered_map<z3::expr, z3::expr>& abs, const vector<z3::expr_vector>& clauses) {
    z3::expr_vector res(c);
    for (unsigned i = 0; i < clauses.size(); ++i) {
        res.push_back(abstract_clause(c, abs, clauses[i]));
    }
    return res;
}

void CDCL_T(z3::context& c, const vector<z3::expr_vector>& clauses) {
    z3::solver prop_solver = z3::solver(c, z3::solver::simple());
    z3::solver theory_solver = z3::solver(c, z3::solver::simple());

    unordered_map<z3::expr, z3::expr> abs;  // 存储理论原子抽象成的命题变量
    prop_solver.add(abstract_clauses(c, abs, clauses));

    theory_solver.add([&]() {
        z3::expr_vector eqs(c);
        for (auto& p : abs) {
            eqs.push_back(p.second == p.first);
        }
        return eqs;
    }());

    while (true) {
        z3::check_result is_sat = prop_solver.check();  // SAT 求解器检查命题骨架是否可满足
        if (z3::sat == is_sat) {                        // 若公式的命题骨架可满足
            z3::model m = prop_solver.get_model();      // 求取一个模型

            z3::expr_vector lits(c);  // 构造一个文字集，对应于模型中文字的取值
            for (auto& p : abs) {
                lits.push_back(m.eval(p.second, true) ? p.second : !p.second);
            }

            if (theory_solver.check(lits) == z3::unsat) {
                prop_solver.add(!mk_and(theory_solver.unsat_core()));
            } else {
                z3::model m = theory_solver.get_model();
                for (unsigned i = 0; i < m.size(); ++i) {
                    if (m[i].is_const()) {
                        std::cout << m[i].name() << " = " << m.get_const_interp(m[i]) << std::endl;
                    }
                }
                return;
            }
        } else {
            cout << is_sat << endl;
            return;
        }
    }
}

void create_clause_set(z3::context& c, const z3::expr& e, vector<z3::expr_vector>& clauses) {
    assert(e.is_app());
    z3::func_decl fd = e.decl();
    Z3_decl_kind kind = fd.decl_kind();
    z3::expr_vector clause(c);

    switch (kind) {
        case Z3_decl_kind::Z3_OP_AND:
            for (size_t i = 0; i < e.num_args(); ++i) {
                create_clause_set(c, e.arg(i), clauses);
            }
            break;
        case Z3_decl_kind::Z3_OP_OR: {
            z3::expr cluase(c);
            for (size_t i = 0; i < e.num_args(); ++i) {
                clause.push_back(e.arg(i));
            }
            clauses.push_back(clause);
            break;
        }
        default: {
            z3::expr cluase(c);
            clause.push_back(e);
            clauses.push_back(clause);
            break;
        }
    }
}

int main() {
    z3::context c;
    string input_file = "examples/f_lia.smt2";

    cout << "Parsing input file: " << input_file << '\n';
    z3::expr_vector formulas = c.parse_file(input_file.c_str());  // bat: reads smt2 file
    z3::expr formula = mk_and(formulas);
    vector<z3::expr_vector> clauses;

    create_clause_set(c, formula, clauses);
    for (auto clause : clauses) {
        for (auto lit : clause) {
            cout << lit.decl().name() << " ";
        }
        cout << endl;
    }

    CDCL_T(c, clauses);
    return 0;
}
