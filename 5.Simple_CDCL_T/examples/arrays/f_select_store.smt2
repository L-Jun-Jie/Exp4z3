(set-logic QF_AUFLIA)

(declare-fun a () (Array Int Int))
(declare-fun b () (Array Int Int))
(declare-fun c () (Array Int Int))
(declare-const x Int)
(declare-const y Int)
(declare-const z Int)

(assert (= (select (store a x 0) y) 0))			;a{x<-0}[y]=0
(assert (> x y))

(check-sat)
(get-model)
