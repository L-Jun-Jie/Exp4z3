(set-logic QF_LIA)
(declare-const x Int)
(declare-const y Int)
(assert (>= (+ y (* 3 x)) 7))
(assert (= y 1))
(check-sat)
(exit)
