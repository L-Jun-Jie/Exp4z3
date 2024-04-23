(set-logic QF_AUFLIA)

(declare-fun a () (Array Int Int))
(declare-fun b () (Array Int Int))
(declare-fun c () (Array Int Int))
(declare-const x Int)
(declare-const y Int)
(declare-const z Int)

(assert (>= (select a x) 0))	;a[x]>=0
(assert (<= (select a y) 2))	;a[y]<=2
(assert (= x y))		;x=y
(check-sat)
(get-model)
