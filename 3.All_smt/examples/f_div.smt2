(set-logic QF_NIA)
(declare-const x Int)
(declare-const y Int)
(assert (>= (div x y) 3))
(check-sat)
(exit)