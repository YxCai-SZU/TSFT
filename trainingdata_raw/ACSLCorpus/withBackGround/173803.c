#include <stdint.h>

/*@
    predicate is_valid_u64_to_i32_cast(uint64_t x) =
        x <= 0xFFFFFFFF;
*/

/*@
    logic integer cast_value(uint64_t x) = (integer)x;
*/

/*@
    lemma cast_range_lemma:
        \forall uint64_t x;
            is_valid_u64_to_i32_cast(x) ==> x >= 0;
*/

/*@
    requires is_valid_u64_to_i32_cast(x);
    ensures \result == (int32_t)cast_value(x);
    assigns \nothing;
*/
int32_t func(uint64_t x)
{
    //@ assert is_valid_u64_to_i32_cast(x);
    //@ assert x >= 0;
    
    int32_t ans = (int32_t)x;
    
    return ans;
}
