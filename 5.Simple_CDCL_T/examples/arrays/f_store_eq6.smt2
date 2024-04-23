(set-logic QF_AUFLIA)

(declare-fun a () (Array Int Int))
(declare-fun b () (Array Int Int))
(declare-const i1 Int)
(declare-const i2 Int)
(declare-const i3 Int)
(declare-const j1 Int)
(declare-const x Int)
(declare-const y Int)
(declare-const z Int)
(declare-const w Int)

(assert (= (store (store (store a i1 x) i2 y) i3 z) (store b j1 w) ))
(assert (= i1 i3))

(check-sat)
(get-model)
