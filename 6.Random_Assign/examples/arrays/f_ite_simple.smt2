(set-logic QF_AUFLIA)

(declare-fun a () (Array Int Int))
(declare-fun b () (Array Int Int))
(declare-fun c () (Array Int Int))
(declare-const x Int)
(declare-const y Int)
(declare-const z Int)

(assert (> (select (store a x (+ x 1)) y) (* 2 y)))			;a{x<-x+1}[y] > 2*y

(apply (! simplify :arith_lhs true :blast_select_store true :pull_cheap_ite true))
