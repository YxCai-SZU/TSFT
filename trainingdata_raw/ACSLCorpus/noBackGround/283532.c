#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 100000000000000000);
    ensures \result >= 0;
    ensures \result <= ((2 * (x)) / 3);
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t quotient;
    int64_t remainder;
    int64_t three;
    int64_t result;
    int64_t two;
    int64_t temp_quotient;
    
    quotient = 0;
    remainder = x;
    three = 3;
    
    /*@
        loop invariant (1 <= (x) && (x) <= 100000000000000000);
        loop invariant 0 <= quotient;
        loop invariant quotient <= ((2 * (x)) / 3);
        loop invariant 0 <= remainder;
        loop invariant remainder == x - quotient * three;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= three)
    {
        remainder -= three;
        quotient += 1;
    }
    
    result = 0;
    two = 2;
    temp_quotient = quotient;
    
    /*@
        loop invariant (1 <= (x) && (x) <= 100000000000000000);
        loop invariant 0 <= result;
        loop invariant result <= ((2 * (x)) / 3);
        loop invariant 0 <= temp_quotient;
        loop invariant temp_quotient == quotient - result * two;
        loop assigns result, temp_quotient;
        loop variant temp_quotient;
    */
    while (temp_quotient >= two)
    {
        temp_quotient -= two;
        result += 1;
    }
    
    //@ assert result >= 0;
    //@ assert result <= ((2 * (x)) / 3);
    
    return result;
}
