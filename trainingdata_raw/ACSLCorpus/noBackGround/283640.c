#include <stdbool.h>

/*@
    requires a > 0 && b > 0;
    ensures \result == true ==> (a - b) * b == a * b - b * b;
    assigns \nothing;
*/
bool prove_nonlinear_arith_prop(int a, int b) {
    bool result;
    //@ assert (a - b) * b == a * b - b * b;
    result = true;
    return result;
}
