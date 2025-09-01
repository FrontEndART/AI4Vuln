#ifndef _SYM_JAVA_SMTFUNCTIONSTRINGS_H_
#define _SYM_JAVA_SMTFUNCTIONSTRINGS_H_

//------Remainder (%) impl for SMT - Start------
#define SMT_INTINT_REMAINDER_OP_DEF "(define-fun % ((a Int) (b Int)) Int (ite (< 0 a) (mod a (abs b)) (- (mod a (abs b)) (abs b))))"
#define SMT_REALREAL_REMAINDER_OP_DEF "(define-fun %rr ((a Real) (b Real)) Real (ite (< 0 a) (- a (* (to_real (to_int (/ a (abs b)))) (abs b) )) (- (- a (* (to_real (to_int (/ a (abs b)))) (abs b) )) (abs b))))"
#define SMT_REALINT_REMAINDER_OP_DEF "(define-fun %ri ((a Real) (b Int)) Real (%rr a (to_real b)))"
#define SMT_INTREAL_REMAINDER_OP_DEF "(define-fun %ir ((a Int) (b Real)) Real (%rr (to_real a) b))"
#define SMT_BOOLINT_COMP "(define-fun bool_to_int ((b Bool)) Int (ite b 1 0))"
#define SMT_REMAINDER_OP_DEF_ALL SMT_INTINT_REMAINDER_OP_DEF SMT_REALREAL_REMAINDER_OP_DEF SMT_REALINT_REMAINDER_OP_DEF SMT_INTREAL_REMAINDER_OP_DEF SMT_BOOLINT_COMP
//------Remainder (%) impl for SMT - End--------

#endif // !_SYM_JAVA_SMTFUNCTIONSTRINGS_H_

