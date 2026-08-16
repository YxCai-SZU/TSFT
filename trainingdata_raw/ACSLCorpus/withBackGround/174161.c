#include <stddef.h>

/*@
    predicate valid_params(integer A, integer B, integer T) =
        1 <= A && A <= 20 &&
        1 <= B && B <= 20 &&
        1 <= T && T <= 20;
*/

/*@
    logic integer compute_result(integer A, integer B, integer T) =
        (T / A) * B;
*/

/*@
    lemma division_bound:
        \forall integer A, integer T;
        valid_params(A, 1, T) ==> T / A <= 20;
*/

/*@
    lemma multiplication_bound:
        \forall integer A, integer B, integer T;
        valid_params(A, B, T) ==> (T / A) * B <= 400;
*/

/*@
    requires valid_params(A, B, T);
    ensures \result == compute_result(A, B, T);
*/
size_t func(size_t A, size_t B, size_t T)
{
    // Variable declarations at top of scope
    size_t ans;
    
    //@ assert A >= 1 && A <= 20;
    //@ assert B >= 1 && B <= 20;
    //@ assert T >= 1 && T <= 20;
    //@ assert T / A <= 20;
    //@ assert (T / A) * B <= 400;
    
    ans = (T / A) * B;
    
    //@ assert ans == compute_result(A, B, T);
    return ans;
}
