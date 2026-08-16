#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100);
    ensures \result == ((((a)) * 6283185307) / 1000000000);
    assigns \nothing;
*/
int64_t func(int64_t a) {
    int64_t multiplier;
    int64_t result;
    int64_t temp;
    int64_t divisor;
    int64_t quotient;
    int64_t remainder;
    
    multiplier = 6283185307;
    result = 0;
    temp = a * multiplier;
    divisor = 1000000000;
    quotient = 0;
    remainder = 0;
    
    //@ assert ((a) * 6283185307) == a * 6283185307;
    
    /*@
        loop invariant 0 <= temp;
        loop invariant temp + quotient * divisor == ((a) * 6283185307);
        loop invariant 0 <= quotient;
        loop assigns temp, quotient;
        loop variant temp;
    */
    while (temp >= divisor) {
        temp -= divisor;
        quotient += 1;
    }
    remainder = temp;
    result = quotient;
    
    //@ assert result * 1000000000 + remainder == ((a) * 6283185307);
    
    return result;
}
