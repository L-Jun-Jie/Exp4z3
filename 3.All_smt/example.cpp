#include <z3++.h>

#include <iostream>
#include <string>

using namespace std;

void block_term(z3::solver s, z3::model m, z3::expr t) {
    s.add(t != m.eval(t, true));
}

void fix_term(z3::solver s, z3::model m, z3::expr t) {
    s.add(t == m.eval(t, true));
}

z3::check_result all_smt_rec(z3::solver s, z3::expr_vector terms, vector<z3::model>& models) {
    if (z3::sat == s.check()) {
        z3::model m = s.get_model();
        models.push_back(m);
        for (unsigned i = 0; i < terms.size(); ++i) {
            s.push();
            block_term(s, m, terms[i]);
            for (unsigned j = 0; j < i; ++j)
                fix_term(s, m, terms[j]);
            all_smt_rec(s, terms, models);
            s.pop();
        }
        return z3::sat;
    }
    return z3::unsat;
}

int main(int argc, char* argv[]) {
    z3::context c;
    z3::solver s(c);

    vector<z3::model> models;
    z3::expr x = c.bool_const("x");
    z3::expr y = c.bool_const("y");
    
    z3::expr_vector terms(c);
    terms.push_back(x);
    terms.push_back(y);

    s.add(mk_or(terms));

    z3::check_result res = all_smt_rec(s, terms, models);

    if (z3::sat == res) {
        unsigned num = 0;
        for (const auto& m : models){
            cout << "model_" << num++ << ":" << endl;
            for (unsigned i = 0; i < m.size(); ++ i){
                if (m[i].is_const()){
                    cout << m[i] << " = " << m.get_const_interp(m[i]) << endl;
                }else {
                    cout << m[i] << " = " << m.get_func_interp(m[i]) << endl;
                }
            }
            cout << endl;
        }
    }

    if (res == z3::unsat) {
        cout << "unsat or unknown !" << endl;
    }
}