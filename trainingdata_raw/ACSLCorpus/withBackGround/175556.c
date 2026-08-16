#include <stdint.h>

/*@
    predicate bound_check_pre(uint32_t x, uint32_t y, uint32_t z) =
        x <= 8 && y <= 8;

    predicate bound_check_post(uint32_t x, uint32_t y, uint32_t z) =
        x * y <= 1000;

    lemma bound_check_lemma:
        \forall uint32_t x, y, z;
            bound_check_pre(x, y, z) ==> bound_check_post(x, y, z);
*/

/*@
    requires bound_check_pre(x, y, z);
    ensures bound_check_post(x, y, z);
    assigns \nothing;
*/
void bound_check(uint32_t x, uint32_t y, uint32_t z) {
    //@ assert x <= 8 && y <= 8;
    //@ assert x * y <= 100;
    //@ assert x * y <= 1000;
}

/*@
    predicate upper_bound_pre(int a, int b, int c) =
        a > 0 && b > 0 && c > 0 &&
        a <= 100 && b <= 100 && c <= 100;

    predicate upper_bound_post(int a, int b, int c) =
        a * b * c <= 1000000;

    lemma upper_bound_lemma:
        \forall int a, b, c;
            upper_bound_pre(a, b, c) ==> upper_bound_post(a, b, c);
*/

/*@
    requires upper_bound_pre(a, b, c);
    ensures upper_bound_post(a, b, c);
    assigns \nothing;
*/
void upper_bound(int a, int b, int c) {
    //@ assert a > 0 && b > 0 && c > 0;
    //@ assert a <= 100 && b <= 100 && c <= 100;
    //@ assert a * b <= 10000;
    //@ assert a * b * c <= 1000000;
}

/*@
    predicate nonlinear_check_pre(uint32_t x, uint32_t y, uint32_t z) =
        x <= 8 && y <= 8;

    predicate nonlinear_check_post(uint32_t x, uint32_t y, uint32_t z) =
        x * y <= 1000;

    lemma nonlinear_check_lemma:
        \forall uint32_t x, y, z;
            nonlinear_check_pre(x, y, z) ==> nonlinear_check_post(x, y, z);
*/

/*@
    lemma lemma_additive_monotonicity:
        \forall uint32_t a, b, c;
            a <= b ==> a + c <= b + c;
*/

/*@
    lemma lemma_multiplicative_monotonicity:
        \forall uint32_t a, b, c;
            a <= b && c > 0 ==> a * c <= b * c;
*/
