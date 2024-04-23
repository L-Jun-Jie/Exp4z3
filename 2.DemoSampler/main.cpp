#include <iostream>

#include "DemoSampler.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[]){
    std::string input_file = argv[1];
    z3::context c;
    DemoSampler ds = DemoSampler(c, input_file);
    ds.parse_formula();
    ds.compute_and_print_formula_stats();
    ds.compute_propositional_skeleton();
    int res = ds.propagation();
    cout << "model count: " << res << endl;
    ds.print_vars_info();
    return 0;
}