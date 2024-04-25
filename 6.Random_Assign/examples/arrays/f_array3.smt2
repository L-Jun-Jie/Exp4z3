(set-logic QF_AUFLIA)

(declare-fun a () (Array Int Int))
(declare-fun b () (Array Int Int))
(declare-fun c () (Array Int Int))
(declare-const x Int)
(declare-const y Int)
(declare-const z Int)

(assert (>= (select a (* 7 x)) (select b (* 2 x))))	;a[7x]>=b[2x]
(assert (= (select a (select a 5)) 9))			;a[a[5]]==9
(assert (< (select a (select b (select c (+ x y)))) 3))	;a[b[c[x+y]]]<3
(assert (> (select b 0) z))				;b[0]>z


(check-sat)
(get-model)
