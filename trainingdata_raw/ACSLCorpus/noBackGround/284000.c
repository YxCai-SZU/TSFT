#include <stdint.h>

/*@
    requires (0 <= (a) <= 10000 && 0 <= (b) <= 10000);
    ensures \result == a + b / 2;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t sum;
    uint32_t temp_b;
    uint32_t quotient;
    uint32_t divisor;
    
    sum = a;
    temp_b = b;
    quotient = 0;
    divisor = 2;
    
    /*@
        loop invariant 0 <= quotient <= b;
        loop invariant temp_b + quotient * divisor == b;
        loop invariant 0 <= temp_b <= b;
        loop assigns temp_b, quotient;
        loop variant temp_b;
    */
    while (temp_b >= divisor) {
        temp_b -= divisor;
        quotient += 1;
    }
    
    sum += quotient;
    
    //@ assert sum == a + b / 2;
    
    return sum;
}
