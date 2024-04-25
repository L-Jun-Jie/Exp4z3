#include <iostream>
// #define _TRACE
#include <z3++.h>

using namespace std;

int main(int argc, char* argv[]) {
    string input_file = "examples/my_test.smt2";

    /* assumptions */
    Z3_enable_trace("assumptions");
    // Z3_enable_trace("internalize_assertions");
    // Z3_enable_trace("after_internalization");
    // Z3_enable_trace("internalize_assertion");
    // Z3_enable_trace("internalize_assertion_ll");
    // Z3_enable_trace("generation");

    /* search */
    Z3_enable_trace("literal_occ");
    // Z3_enable_trace("after_init_search");
    Z3_enable_trace("before_search");
    Z3_enable_trace("search");
    Z3_enable_trace("search_lite");
    Z3_enable_trace("search_detail");
    Z3_enable_trace("bounded_search");
    Z3_enable_trace("after_search");
    Z3_enable_trace("search_bug");

    /* decide */
    Z3_enable_trace("decide");
    Z3_enable_trace("decide_detail");
    Z3_enable_trace("random_split");

    /* assign */
    Z3_enable_trace("guessed_literals");
    Z3_enable_trace("assign_core");
    Z3_enable_trace("phase_selection");

    /* propagate */
    Z3_enable_trace("propagate");
    Z3_enable_trace("propagate_atoms");
    Z3_enable_trace("propagate_eqs");
    Z3_enable_trace("after_first_propagate");

    Z3_enable_trace("final_check_result");
    Z3_enable_trace("solver_na2as");
    Z3_enable_trace("set_conflict");
    Z3_enable_trace("theory_case_split");
    Z3_enable_trace("activity_profile");
    Z3_enable_trace("assigned_literals_per_lvl");
    Z3_enable_trace("guessed_literals");

    /* my trace */
    Z3_enable_trace("bcp");
    Z3_enable_trace("decide_var");

    z3::context c;
    z3::solver s(c, z3::solver::simple());

    z3::expr_vector formulas = c.parse_file(input_file.c_str());

    z3::expr formula = mk_and(formulas);

    s.add(formula);

    z3::check_result res = s.check();

    if (z3::sat == res) {
        z3::model m = s.get_model();

        for (unsigned i = 0; i < m.size(); ++i) {
            if (m[i].is_const()) {
                cout << m[i].name() << " = " << m.get_const_interp(m[i]) << endl;
            }
        }
    } else {
        cout << "unsat!" << endl;
    }

    return 0;
}