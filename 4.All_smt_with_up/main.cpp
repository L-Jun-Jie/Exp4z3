#include <z3++.h>

#include <iostream>

#include "user_propagator.h"

using namespace std;

int main() {
    z3::context context;
    z3::solver s(context, z3::solver::simple());
    std::unordered_map<z3::expr, unsigned> idMapping;
    user_propagator* p = new user_propagator(&s, idMapping, 4);

    z3::expr_vector vars(context);
    // 创建变量
    for (int i = 0; i < 4; ++i) {
        string var_name = "x!" + to_string(i);
        z3::expr tmp = context.bool_const(var_name.c_str());
        vars.push_back(tmp);
    }

    // 注册变量
    for (unsigned i = 0; i < vars.size()-1; ++i) {
        p->add(vars[i]);
        idMapping[vars[i]] = i;
    }

    z3::expr e1 = vars[0] || !vars[1];
    z3::expr e2 = vars[2] || vars[3];
    z3::expr e3 = !vars[2] || vars[0];
    z3::expr_vector formulas(context);

    formulas.push_back(e1);
    formulas.push_back(e2);
    formulas.push_back(e3);
    s.add(mk_and(formulas));

    if (z3::sat == s.check())
        cout << "is sat" << endl;

    int res = p->getModelCount();  // 计算模型数
    cout << "model num = " << res << std::endl;
    delete p;
    return 0;
}