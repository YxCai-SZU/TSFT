/*@
    predicate is_valid_params(integer a, integer p) =
        0 <= a && a <= 100 &&
        0 <= p && p <= 100;

    logic integer calculate_result(integer a, integer p) =
        p + a * 3;

    lemma result_bound: \forall integer a, p;
        is_valid_params(a, p) ==> calculate_result(a, p) <= p + a * 3;
*/

#include <stdint.h>

/*@
    requires is_valid_params(a, p);
    ensures \result <= p + a * 3;
    ensures \result == (p + a * 3) / 2;
*/
uint64_t func(uint64_t a, uint64_t p)
{
    // Variable declarations at top of scope
    uint64_t result;
    uint64_t half_result;
    uint64_t temp_result;
    
    result = p + a * 3;
    half_result = 0;
    temp_result = result;
    
    //@ assert result == p + a * 3;
    
    /*@
        loop invariant 0 <= half_result;
        loop invariant half_result <= result / 2;
        loop invariant temp_result == result - 2 * half_result;
        loop assigns half_result, temp_result;
    */
    while (temp_result >= 2)
    {
        //@ assert temp_result >= 2;
        half_result += 1;
        temp_result -= 2;
        //@ assert temp_result == result - 2 * half_result;
    }
    
    //@ assert half_result == (p + a * 3) / 2;
    return half_result;
}
