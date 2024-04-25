# Exp4z3
Z3-based experiments to improve understanding of the Z3 architecture and solution process.
## 0. Configuration Z3
Installing Z3 with GCC (see the Z3 repositories for other installation methods).

```shell
$ python3 scripts/mk_make.py
$ cd build
$ make
$ sudo make install
```

If you need to modify the Z3 source code for debugging, you can choose to turn on debug mode at compile time to display trace information.
```shell
$ python3 scripts/mk_make.py --debug --trace
$ cd build
$ make
$ sudo make install
```

## 1. N-Queens Problem
Place `n` queens on an `n×n` board and require that no two queens can attack each other (i.e., they cannot be in the same row, column, or diagonal).

## 2. DemoSampler
Tried to implement a simple SMT sampler using Z3's user propagation feature, but unfortunately it didn't work :(

## 3.All_smt
Reference to the C++ version of the ALL-SMT code written by [programmingz3](https://z3prover.github.io/papers/programmingz3.html#sec-blocking-evaluations).

## 4. ALL_smt_with_up
The C++ version of the user-propagated ALL-SMT code was also implemented with reference to [programmingz3](https://z3prover.github.io/papers/programmingz3.html#sec-all-smt-with-user-propagators).

## 5. Simple_CDCL_T
Still referring to [programmingz3](https://z3prover.github.io/papers/programmingz3.html#sec-cdclt), the C++ version of the implementation is based on Simple_CDCL(T).

## 6. Random_Assign
Attempting to randomize Z3 in variable decision making and assignment selection is a groundwork for implementing the SMT sampler. Unfortunately, only the randomization of propositional formula variables and assignments has been carried out so far, and subsequent work needs to be deepened.

## End
All the contents of this project are my personal understanding, if there is any inappropriate, welcome to exchange corrections.

email: sugernadmaster@163.com