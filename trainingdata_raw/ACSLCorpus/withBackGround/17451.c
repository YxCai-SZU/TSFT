#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer compute_result(integer a, integer b) = b / a;
*/

/*@
    requires valid_inputs(a, b);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result == compute_result(a, b);
*/
int64_t func(uint64_t a, uint64_t b)
{
    // Variable declarations at scope top
    uint64_t result;
    
    //@ assert valid_inputs(a, b);
    
    result = b / a;
    
    //@ assert result == compute_result(a, b);
    
    return (int64_t)result;
}
