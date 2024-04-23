(set-logic QF_AUFLIA)

(declare-fun a () (Array Int Int))
(declare-fun b () (Array Int Int))
(declare-const x Int)
(declare-const y Int)
(declare-const z Int)
(declare-const w Int)

(assert (= (store a x z) (store b y w)))
(assert (> (select a 0) 7))

(check-sat)
(get-model)
