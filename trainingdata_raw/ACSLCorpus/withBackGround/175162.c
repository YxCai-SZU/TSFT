#include <stdint.h>

/*@
    predicate in_range_a(integer a) = 1 <= a <= 12;
    predicate in_range_b(integer b) = 1 <= b <= 31;
    
    logic integer condition_1(integer a, integer b) = 
        (a <= 9 && b >= 10) ? 1 : 0;
    
    logic integer condition_2(integer a, integer b) = 
        (a > 9 && b >= 10 + (a - 10) * 2) ? 1 : 0;
    
    lemma arithmetic_bound: 
        \forall integer a; in_range_a(a) ==> 10 + (a - 10) * 2 <= 14;
*/

/*@
    requires in_range_a(a) && in_range_b(b);
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> 
        (a <= 9 && b >= 10) || (a > 9 && b >= 10 + (a - 10) * 2);
    ensures \result == 0 ==> 
        !(a <= 9 && b >= 10) && !(a > 9 && b >= 10 + (a - 10) * 2);
*/
int32_t func(uint32_t a, uint32_t b) {
    int32_t a_i32;
    int32_t b_i32;
    int32_t result;
    
    a_i32 = (int32_t)a;
    b_i32 = (int32_t)b;
    
    //@ assert in_range_a(a_i32) && in_range_b(b_i32);
    //@ assert 10 + (a_i32 - 10) * 2 <= 14;
    
    if (a_i32 <= 9 && b_i32 >= 10) {
        result = 1;
    } else if (a_i32 > 9 && b_i32 >= 10 + (a_i32 - 10) * 2) {
        result = 1;
    } else {
        result = 0;
    }
    
    return result;
}
