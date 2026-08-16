#include <stdint.h>

/*@ predicate in_range(integer a) = 1 <= a <= 100; */

/*@ logic integer abs_diff(integer a, integer b) = 
      a > b ? a - b : b - a; */

/*@ lemma result_bounds: 
      \forall integer a, b, diff, result;
        in_range(a) && in_range(b) && 
        diff == abs_diff(a, b) && 
        result == diff * 2 ==>
        0 <= result <= 198; */

/*@
requires in_range(a) && in_range(b);
ensures \result >= -1;
ensures \result < 0x80000000;
assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b) {
    uint32_t diff;
    uint32_t result;
    uint32_t quotient;
    uint32_t remainder;
    
    //@ assert in_range(a) && in_range(b);
    
    if (a > b) {
        diff = a - b;
    } else {
        diff = b - a;
    }
    //@ assert diff == abs_diff(a, b);
    
    result = diff * 2;
    quotient = 0;
    remainder = result;
    
    /*@
    loop invariant 0 <= quotient <= result / 11;
    loop invariant remainder == result - quotient * 11;
    loop invariant result == diff * 2;
    loop invariant in_range(a) && in_range(b);
    loop assigns quotient, remainder;
    loop variant remainder;
    */
    while (remainder >= 11) {
        quotient += 1;
        remainder -= 11;
    }
    
    if (remainder == 0) {
        result = quotient;
    } else {
        result = quotient + 1;
    }
    
    if (result <= 100) {
        return (int32_t)result;
    } else {
        return -1;
    }
}
