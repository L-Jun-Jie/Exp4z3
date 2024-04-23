(set-logic QF_AUFLIA)

(declare-fun a () (Array Int Int))
(declare-fun b () (Array Int Int))
(declare-fun c () (Array Int Int))
(declare-const x Int)
(declare-const y Int)
(declare-const z Int)

(assert (= (select a x) 0))			;a[x]=0
(assert (= (select a x) (select b (* 2 x))))	;a[x]=b[2x]
(assert (> (select c y) (* 3 (select b x))))	;c[y]>3b[x]
(assert (not (or (> x 8) (< y 6))))
(assert (<= z (* 3 y)))
(assert (>= (* x 3) y))

(check-sat)
(get-model)
