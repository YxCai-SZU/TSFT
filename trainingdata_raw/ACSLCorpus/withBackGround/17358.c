#include <stdint.h>

/*@
    predicate valid_input(integer A, integer P) =
        0 <= A && A <= 100 &&
        0 <= P && P <= 100;

    logic integer compute_result(integer A, integer P) =
        (A * 3 + P) / 2;

    lemma intermediate_bounds:
        \forall integer A, P;
        valid_input(A, P) ==>
        A * 3 <= 300 &&
        A * 3 + P <= 400;
*/

/*@
    requires valid_input(A, P);
    ensures \result == compute_result(A, P);
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t P)
{
    // Variable declarations at scope top
    uint32_t K;
    uint32_t ret;

    //@ assert valid_input(A, P);
    
    //@ assert A * 3 <= 300;
    //@ assert A * 3 + P <= 400;

    K = A * 3 + P;
    ret = K / 2;
    
    //@ assert ret == compute_result(A, P);
    return ret;
}
