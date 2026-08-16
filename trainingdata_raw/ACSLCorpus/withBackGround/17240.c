#include <stdint.h>

/*@
    predicate valid_inputs(integer A, integer P) =
        0 <= A <= 100 && 0 <= P <= 100;
    
    logic integer compute_result(integer A, integer P) =
        (A * 3 + P) / 2;
*/

/*@
    requires valid_inputs(A, P);
    ensures \result == compute_result(A, P);
    assigns \nothing;
*/
uint64_t func(uint64_t A, uint64_t P)
{
    // Variable declarations at scope top
    uint64_t result;
    
    //@ assert 0 <= A * 3 <= 300;
    //@ assert 0 <= A * 3 + P <= 400;
    
    result = (A * 3 + P) / 2;
    return result;
}
