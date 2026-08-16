#include <stdint.h>

/*@
    requires a > 0 && b > 0 && a <= 1000 && b <= 1000;
    ensures \result == a * b;
    ensures \result > 0;
    ensures \result <= 1000000;
    assigns \nothing;
*/
int32_t nonlinear_arith_example(int32_t a, int32_t b) {
    //@ assert a * b <= 1000000;
    //@ assert a * b >= 1;
    return a * b;
}
