#include <stdbool.h>

/*@
    requires (10 <= (n) && (n) <= 99);
    ensures \result == (n / 10 == 9 || n % 10 == 9);
*/
bool func(unsigned int n)
{
    unsigned int quotient;
    unsigned int remainder;
    unsigned int divisor;
    
    quotient = 0;
    remainder = n;
    divisor = 10;
    
    /*@
        loop invariant 10 <= n && n <= 99;
        loop invariant remainder <= n;
        loop invariant quotient >= 0;
        loop invariant remainder == n - divisor * quotient;
        loop assigns remainder, quotient;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        remainder -= divisor;
        quotient += 1;
    }
    
    //@ assert quotient == n / 10;
    //@ assert remainder == n % 10;
    
    return quotient == 9 || remainder == 9;
}
