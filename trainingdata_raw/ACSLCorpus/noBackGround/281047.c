#include <stdint.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == (((n) + 1) / 2);
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    int64_t result;
    int64_t quotient;
    int64_t remainder;
    
    result = n + 1;
    quotient = 0;
    remainder = result;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= quotient <= (((n) + 1) / 2);
        loop invariant remainder == result - 2 * quotient;
        loop invariant result == n + 1;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 2)
    {
        //@ assert remainder >= 2;
        quotient += 1;
        remainder -= 2;
    }
    
    //@ assert quotient == (((n) + 1) / 2);
    return quotient;
}
