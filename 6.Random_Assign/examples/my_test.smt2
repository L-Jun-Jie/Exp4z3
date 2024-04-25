; Example of a propositional formula SMT2 file
(set-logic QF_UF) ; Set the logic for quantifier-free uninterpreted functions, adequate for propositional logic.

; Declare propositional variables
(declare-const p Bool)
(declare-const q Bool)
(declare-const r Bool)

; Assert logical constraints
(assert (or p q))            ; p or q
(assert (or (not p) r))      ; not p or r
(assert (or (not q) (not r))) ; not q or not r
(assert (or p (not q)))      ; p and not q

; Check satisfiability
(check-sat)

; Get values if satisfiable
(get-model)
