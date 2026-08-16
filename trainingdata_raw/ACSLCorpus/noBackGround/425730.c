#include <stdbool.h>

/*@
    requires 10 <= a <= 99;
    ensures \result == (a / 10 == 7 || a % 10 == 7);
    assigns \nothing;
*/
bool func(unsigned int a)
{
    unsigned int quotient = 0;
    unsigned int remainder = a;
    
    /*@
        loop invariant 0 <= quotient <= a / 10;
        loop invariant remainder == a - quotient * 10;
        loop invariant remainder >= 0 && remainder < 100;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 10)
    {
        remainder -= 10;
        quotient += 1;
    }
    
    //@ assert quotient == a / 10 && remainder == a % 10;
    
    return (quotient == 7) || (remainder == 7);
}
