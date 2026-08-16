#include <stdint.h>

/*@
    predicate is_even(integer x) = x % 2 == 0;
    predicate is_odd(integer x) = x % 2 != 0;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> is_even(a + b);
    ensures \result == 1 ==> is_odd(a + b);
*/
int32_t func(uint32_t a, uint32_t b) {
    int32_t result;
    int32_t is_even;
    int32_t abs_result;
    
    result = (int32_t)(a + b);
    is_even = 1;
    
    if (result < 0) {
        abs_result = -result;
    } else {
        abs_result = result;
    }
    
    /*@
        loop invariant 0 <= abs_result <= a + b;
        loop invariant abs_result % 2 == (a + b) % 2;
        loop assigns abs_result;
    */
    while (abs_result >= 2) {
        //@ assert abs_result >= 2;
        abs_result -= 2;
    }
    
    if (abs_result == 0) {
        is_even = 0;
    }
    
    //@ assert is_even == 0 ==> is_even(a + b);
    return is_even;
}
