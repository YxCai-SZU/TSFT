#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100000;
    
    logic integer compute_result(integer x) = 
        (x / 500) * 1000 + ((x % 500) / 5) * 5;
*/

/*@
    requires valid_range(x);
    ensures \result == compute_result(x);
*/
int32_t func(uint32_t x) {
    uint32_t quotient_500 = 0;
    uint32_t remainder_500 = x;
    uint32_t quotient_5 = 0;
    uint32_t remainder_5 = 0;
    int32_t result = 0;
    
    //@ assert valid_range(x);
    
    /*@
        loop invariant 0 <= quotient_500 <= x / 500;
        loop invariant remainder_500 == x - quotient_500 * 500;
        loop invariant remainder_500 >= 0;
        loop invariant valid_range(x);
        loop assigns quotient_500, remainder_500;
        loop variant remainder_500;
    */
    while (remainder_500 >= 500) {
        remainder_500 -= 500;
        quotient_500 += 1;
        //@ assert remainder_500 == x - quotient_500 * 500;
    }
    
    remainder_5 = remainder_500;
    
    /*@
        loop invariant 0 <= quotient_5 <= remainder_500 / 5;
        loop invariant remainder_5 == remainder_500 - quotient_5 * 5;
        loop invariant remainder_5 >= 0;
        loop invariant valid_range(x);
        loop assigns quotient_5, remainder_5;
        loop variant remainder_5;
    */
    while (remainder_5 >= 5) {
        remainder_5 -= 5;
        quotient_5 += 1;
        //@ assert remainder_5 == remainder_500 - quotient_5 * 5;
    }
    
    result = (int32_t)(quotient_500 * 1000 + quotient_5 * 5);
    //@ assert result == compute_result(x);
    return result;
}

int main() {
    return 0;
}
