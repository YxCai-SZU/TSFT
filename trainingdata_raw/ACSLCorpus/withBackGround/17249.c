#include <stdint.h>

/*@
    predicate is_valid_input(integer x) =
        0 <= x <= 1000000000;
*/

/*@
    logic integer compute_result(integer ux) =
        (ux / 500 * 1000) + ((ux % 500) / 5 * 5);
*/

/*@
    lemma result_non_negative:
        \forall integer ux; ux >= 0 ==> compute_result(ux) >= 0;
*/

/*@
    requires is_valid_input(x);
    ensures \result >= 0;
*/
int64_t func(int64_t x)
{
    // Variable declarations
    uint64_t ux;
    uint64_t result;
    int64_t final_result;
    
    //@ assert x >= 0 && x <= 1000000000;
    
    ux = (uint64_t)x;
    
    //@ assert ux >= 0;
    
    result = (ux / 500 * 1000) + ((ux % 500) / 5 * 5);
    
    //@ assert result == compute_result(ux);
    //@ assert result >= 0;
    
    final_result = (int64_t)result;
    
    //@ assert final_result >= 0;
    
    return final_result;
}
