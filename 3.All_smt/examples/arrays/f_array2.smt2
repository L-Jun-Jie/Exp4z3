(set-logic QF_AUFLIA)

(declare-fun a () (Array Int Int))
(declare-fun b () (Array Int Int))
(declare-fun c () (Array Int Int))
(declare-const x Int)
(declare-const y Int)
(declare-const z Int)

(assert (>= (select a (* 7 x)) 9))		;a[7x]>=9
(assert (< 8 (select a (- y 4))))		;8<a[y-4]
(assert (>= y 5))				;y>=5
(assert (< (+ x z) 7))				;x+z<7


(check-sat)
(get-model)
