(set-logic QF_AUFLIA)

(declare-fun a () (Array Int Int))
(declare-fun b () (Array Int Int))
(declare-const i1 Int)
(declare-const i2 Int)
(declare-const j1 Int)
(declare-const j2 Int)
(declare-const x Int)
(declare-const y Int)
(declare-const z Int)
(declare-const w Int)

(assert (= (store a i1 x) (store b j1 z)))
(assert (> (select a 0) 7))
(assert (<= (select b 20) -2))

(check-sat)
(get-model)
