#include "DemoSampler.h"

DemoSampler::DemoSampler(z3::context &_c, std::string &in_file)
    : c(_c), original_formula(_c), params(_c), model(_c),
      internal_solver(_c), external_solver(_c), input_file(in_file), skeletonAtoms(c) {}

/* Parses the formula and stores the result in original_formula */
void DemoSampler::parse_formula() {
  std::cout << "Parsing input file: " << input_file << '\n';
  z3::expr_vector formulas = c.parse_file(input_file.c_str());  // bat: reads smt2 file
  std::cout << "Number of formulas in file: " << formulas.size() << '\n';
  z3::expr formula = mk_and(formulas);  // 将同一文件的公式合取为一个公式
  Z3_ast ast = formula;                 // 将公式转换为 ast
  if (ast == nullptr) {
    std::cerr << "Could not read input formula." << std::endl;
    failure_cause = "Could not read input formula.";
    safe_exit(1);
  }
  original_formula = formula;  // 存储初始公式
  // if (debug)
  //   std::cout << "Read formula: " << original_formula << std::endl;
}

/* Recursively calculating the number of each type of variable in a formula */
void DemoSampler::_compute_formula_stats_aux(const z3::expr &e, int depth) {
  assert(e.is_app());
  z3::func_decl fd = e.decl();

  /* 处理叶子节点 */
  if (e.is_const()) {                                   // 若表达式是零元函数
    std::string v_name = fd.name().str();             // 获取常量名
    if (var_names.find(v_name) == var_names.end()) {  // 若该常量未曾保存
      var_names.insert(v_name);                     // 将其作为常量保存
      variables.push_back(fd);                      // 保存其函数声明
      variable_names.push_back(v_name);             // 也将其作为变量保存？？
      assert(fd.is_const());
      switch (fd.range().sort_kind()) {
        case Z3_BOOL_SORT:++num_bools;
          break;
        case Z3_INT_SORT:++num_ints;
          break;
        case Z3_REAL_SORT:++num_reals;
          break;
        default:std::cout << "Invalid sort\n";
          failure_cause = "Invalid sort.";
          safe_exit(1);
      }
    }
  }
  if (depth > max_depth) {  // 更新最大深度
    max_depth = depth;
  }

  /* 递归计算 AST 的信息 */
  for (size_t i = 0; i < e.num_args(); ++i) {
    // std::cout << "depth = " << depth << " arg_id = " << i << " arg =  " << e.arg(i).to_string() << std::endl;
    _compute_formula_stats_aux(e.arg(i), depth + 1);
  }
}

void DemoSampler::compute_and_print_formula_stats() {
  // TODO save formula theory
  _compute_formula_stats_aux(original_formula);
  //	std::cout << "Nodes " << sup.size() << '\n';
  //	std::cout << "Internal nodes " << sub.size() << '\n';
  std::cout << "-------------FORMULA STATISTICS-------------" << '\n';
  std::cout << "Bools " << num_bools << '\n';
  std::cout << "Ints " << num_ints << '\n';
  std::cout << "Reals " << num_reals << '\n';
  std::cout << "Formula tree depth " << max_depth << '\n';
  std::cout << "--------------------------------------------" << '\n';
}

void DemoSampler::compute_propositional_skeleton() {
  _compute_propositional_skeleton(original_formula);
}

void DemoSampler::_compute_propositional_skeleton(const z3::expr &e) {
  assert(e.is_app());
  z3::func_decl fd = e.decl();
  Z3_decl_kind kind = fd.decl_kind();
  if (kind != Z3_decl_kind::Z3_OP_AND && kind != Z3_decl_kind::Z3_OP_OR && kind != Z3_decl_kind::Z3_OP_NOT) {
    skeletonAtoms.push_back(e);
    num_atoms++;
    return;
  }

  /* 递归计算 AST 的信息 */
  for (size_t i = 0; i < e.num_args(); ++i) {
    _compute_propositional_skeleton(e.arg(i));
  }
}

/* debug vars info */
void DemoSampler::print_vars_info() {
  std::cout << "-------------var_names-------------" << '\n';
  for (const auto &v : var_names) {
    std::cout << v << std::endl;
  }
  std::cout << "-----------------------------------" << '\n';
  std::cout << "-------------variable_names--------" << '\n';
  for (const auto &v : variable_names) {
    std::cout << v << std::endl;
  }
  std::cout << "-----------------------------------" << '\n';
  std::cout << "-------------variables-------------" << '\n';
  for (const auto &v : variables) {
    std::cout << v << std::endl;
  }
  std::cout << "-----------------------------------" << '\n';
  std::cout << "-------------skeletonAtoms---------" << '\n';
  for (auto v : skeletonAtoms) {
    std::cout << v << std::endl;
  }
  std::cout << "-----------------------------------" << '\n';
}

void DemoSampler::safe_exit(int exitcode) {
  if (exitcode) {
    result = "failure";
  } else {
    result = "success";
  }
  exit(exitcode);
}

int DemoSampler::propagation() {
  std::unordered_map<z3::expr, unsigned> idMapping;
  up = new user_propagator(&internal_solver, &external_solver, idMapping);

  // 将理论原子映射到整数
  // std::cout << "skeletonAtoms.size()" << skeletonAtoms.size() << std::endl;
  for (unsigned i = 0; i < skeletonAtoms.size(); ++i) {
    up->add(skeletonAtoms[i]);
    idMapping[skeletonAtoms[i]] = i;
  }

  if (internal_solver.check() == z3::sat) {
    z3::model m = internal_solver.get_model();
    for (unsigned i = 0; i < m.size(); i++) {
      z3::func_decl v = m[i];
      // 输出变量名和赋值
      std::cout << v.name() << " = " << m.get_const_interp(v) << std::endl;
    }
  }else{
    std::cout << "unsat" << std::endl;
  }

  int res = up->getModelCount();
  delete up;
  return res;
}


