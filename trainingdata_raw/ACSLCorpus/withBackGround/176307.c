#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;
*/

/*@
    logic integer compute_result(integer a, integer b) =
        a - 2 * b > 0 ? a - 2 * b : 0;
*/

/*@
    lemma result_bounds:
        \forall integer a, b;
        valid_range(a, b) ==>
        compute_result(a, b) >= 0 &&
        compute_result(a, b) <= a;
*/

/*@
    requires valid_range(A, B);
    ensures \result >= 0 && \result <= A;
*/
int32_t func(int32_t A, int32_t B)
{
    int32_t result;
    //@ assert valid_range(A, B);
    
    if (A - 2 * B > 0) {
        result = A - 2 * B;
    } else {
        result = 0;
    }
    
    //@ assert result == compute_result(A, B);
    //@ assert result >= 0;
    //@ assert result <= A;
    
    return result;
}
