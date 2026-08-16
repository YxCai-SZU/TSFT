#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 2 <= a && a <= 100;
    predicate b_in_range(integer b) = 2 <= b && b <= 100;
    predicate result_correct(integer a, integer b, integer res) = 
        res == (a - 1) * (b - 1);
*/

/*@
    logic integer max_u32_value = 4294967295;
    logic integer max_i32_value = 2147483647;
*/

/*@
    lemma multiplication_bounds:
        \forall integer a, b;
            a_in_range(a) && b_in_range(b) ==>
            (a - 1) * (b - 1) <= 99 * 99;
*/

/*@
    lemma conversion_safe:
        \forall integer x;
            0 <= x && x <= 99 ==>
            x <= max_i32_value;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures result_correct(a, b, \result);
*/
int32_t func(int32_t a, int32_t b)
{
    uint32_t a_unsigned;
    uint32_t b_unsigned;
    uint32_t a_sub_1;
    uint32_t b_sub_1;
    int32_t a_sub_1_signed;
    int32_t b_sub_1_signed;
    int32_t result;
    
    // Convert to unsigned
    if (a < 0) {
        a_unsigned = (uint32_t)(-a);
    } else {
        a_unsigned = (uint32_t)a;
    }
    
    if (b < 0) {
        b_unsigned = (uint32_t)(-b);
    } else {
        b_unsigned = (uint32_t)b;
    }
    
    // Manual subtraction
    if (a_unsigned > 1) {
        a_sub_1 = a_unsigned - 1;
    } else {
        a_sub_1 = 0;
    }
    
    if (b_unsigned > 1) {
        b_sub_1 = b_unsigned - 1;
    } else {
        b_sub_1 = 0;
    }
    
    //@ assert a_sub_1 <= 99;
    //@ assert b_sub_1 <= 99;
    //@ assert a_sub_1 * b_sub_1 <= 99 * 99;
    
    // Convert back to signed
    a_sub_1_signed = (int32_t)a_sub_1;
    b_sub_1_signed = (int32_t)b_sub_1;
    
    //@ assert a_sub_1_signed == (int32_t)a_sub_1;
    //@ assert b_sub_1_signed == (int32_t)b_sub_1;
    //@ assert a_sub_1_signed * b_sub_1_signed <= 99 * 99;
    
    result = a_sub_1_signed * b_sub_1_signed;
    
    //@ assert result == (a - 1) * (b - 1);
    return result;
}
