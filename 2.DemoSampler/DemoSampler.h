#ifndef DEMOSAMPLER_H
#define DEMOSAMPLER_H

#include <z3++.h>
#include <fstream>
#include <random>

#include "common.h"
#include "user_propagator.h"

class DemoSampler {
 public:
  z3::context &c;
  z3::expr original_formula;

 private:
  /* for randomness */
  std::random_device rd;
  std::mt19937 g{rd()};

  /* Z3 Internal Objects */
  z3::params params;              // 参数对象
  z3::model model;                // 用于采样的模型种子
  z3::solver internal_solver;     // 用于用户传播的求解器
  z3::solver external_solver;     // 用于在用户传播器内处理约束的求解器

  /* samples */
  std::ofstream results_file;               // 输出文件
  std::unordered_set<std::string> samples;  // 用于存储样本（避免重复样本输出）
  unsigned samples_num = 0;                 // 采样数

  /* file */
  std::string input_file;  // 输入文件
  std::string output_dir;  // 输出目录
  std::string json_file;   // json输出文件的名称

  /* variable info */
  z3::expr_vector skeletonAtoms;                 // 命题骨架中的原子集
  int num_atoms = 0;
  std::vector<z3::func_decl> variables;          // 变量（零元函数）的函数声明
  std::vector<std::string> variable_names;       // 公式中变量的名称
  std::unordered_set<std::string> var_names = {  // 公式中的常量和变量
      "bv", "Int", "true",
      "false"};

  /* formula info */
  int num_bools = 0, num_ints = 0, num_reals = 0;
  int max_depth = 0;

  /* debug */
  bool debug = false;
  std::string failure_cause;  // explanation for failure if result==failure

  /* solving statistics */
  std::string result = "unknown";  // success/failure

  /* user propagator */
  user_propagator *up;

 public:
  DemoSampler(z3::context &_c, std::string &in_file);

  /* input parse */
  void parse_formula();

  void _compute_formula_stats_aux(const z3::expr &e, int depth = 0);

  void compute_and_print_formula_stats();

  void compute_propositional_skeleton();

  void _compute_propositional_skeleton(const z3::expr &e);

  /* debug */
  void print_vars_info();

  /* user propagator */
  int propagation();

  void safe_exit(int exitcode);
};

#endif