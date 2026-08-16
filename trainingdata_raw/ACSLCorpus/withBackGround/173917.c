#include <stdint.h>

/*@
    predicate is_valid_input(integer x) = 101 <= x <= 1000000000000000000;
    logic integer compute_result(integer x) = (x - 100) / 100 + 1;
    lemma result_positive: \forall integer x; is_valid_input(x) ==> compute_result(x) > 0;
*/

/*@
    requires is_valid_input(x);
    ensures \result > 0;
    ensures \result == compute_result(x);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    // Variable declarations at top of scope
    uint64_t result;
    
    //@ assert x > 100;
    //@ assert x - 100 <= 18446744073709551515;
    //@ assert (x - 100) / 100 <= 184467440737095515;
    //@ assert (x - 100) / 100 >= 0;
    //@ assert (x - 100) / 100 + 1 <= 18446744073709551615;
    
    result = (x - 100) / 100 + 1;
    return result;
}
