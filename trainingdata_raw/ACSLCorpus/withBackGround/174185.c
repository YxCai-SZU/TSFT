#include <stddef.h>

/*@
    predicate valid_params(integer A, integer B, integer T) =
        1 <= A && A <= 20 &&
        1 <= B && B <= 20 &&
        1 <= T && T <= 20;

    logic integer compute_result(integer A, integer B, integer T) =
        (T / A) * B;

    lemma result_bounds:
        \forall integer A, B, T;
        valid_params(A, B, T) ==> 
        compute_result(A, B, T) <= 400;
*/

/*@
    requires valid_params(A, B, T);
    ensures \result == compute_result(A, B, T);
    assigns \nothing;
*/
size_t func(size_t A, size_t B, size_t T)
{
    // Variable declarations at scope top
    size_t result;

    //@ assert 1 <= A && A <= 20;
    //@ assert 1 <= B && B <= 20;
    //@ assert 1 <= T && T <= 20;
    //@ assert T / A <= 20;
    //@ assert (T / A) * B <= 400;

    result = (T / A) * B;
    return result;
}
