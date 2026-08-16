#include <stdint.h>

/*@
    predicate valid_range(integer a) =
        1 <= a && a <= 9;

    // Logical computation for multiplication
    logic integer safe_mult(integer a, integer b) =
        a * b;

    // Proof lemma about multiplication bounds
    lemma mult_bounds: \forall integer a, b;
        valid_range(a) && valid_range(b) ==> 1 <= safe_mult(a, b) && safe_mult(a, b) <= 81;
*/

/*@
    requires valid_range(A) && valid_range(B);
    ensures \result == A * B || \result == -1;
    ensures \result >= 0 || \result == -1;
*/
int64_t func(int64_t A, int64_t B)
{
    // Declare all variables at the top
    int64_t result;

    if (A > 0 && B > 0 && A + B <= 9) {
        //@ assert 1 <= A * B && A * B <= 81;
        result = A * B;
    } else {
        result = -1;
    }

    return result;
}
