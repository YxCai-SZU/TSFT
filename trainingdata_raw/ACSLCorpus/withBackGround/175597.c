#include <stdint.h>

/*@
    predicate is_u32_range(uint64_t x) = x <= 0xFFFFFFFF;
*/

/*@
    logic integer cast_to_i32(uint64_t x) = (integer)((uint32_t)x);
*/

/*@
    lemma cast_preserves_value:
        \forall uint64_t x;
            is_u32_range(x) ==> cast_to_i32(x) == (integer)x;
*/

/*@
    requires is_u32_range(x);
    ensures \result == (int32_t)((uint32_t)x);
    assigns \nothing;
*/
int32_t func(uint64_t x)
{
    // Variable declarations at top of scope
    uint32_t temp_u32;
    int32_t result;

    //@ assert is_u32_range(x);
    
    temp_u32 = (uint32_t)x;
    //@ assert temp_u32 == (uint32_t)x;
    
    result = (int32_t)temp_u32;
    //@ assert result == (int32_t)temp_u32;
    
    return result;
}
