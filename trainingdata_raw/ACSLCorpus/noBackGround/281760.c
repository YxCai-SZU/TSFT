#include <stdbool.h>

/*@
    requires 10 <= n <= 99;
    ensures \result == (n % 10 == 9 || n >= 90);
    assigns \nothing;
 */
bool func(unsigned int n)
{
    unsigned int remainder;
    remainder = n;

    /*@
        loop invariant (10 <= (n) <= 99 &&
        0 <= (remainder) <= (n) &&
        ((remainder) == (n) || (remainder) == (n) - 10 || (remainder) == (n) - 20 || (remainder) == (n) - 30 || 
         (remainder) == (n) - 40 || (remainder) == (n) - 50 || (remainder) == (n) - 60 || (remainder) == (n) - 70 || 
         (remainder) == (n) - 80 || (remainder) == (n) - 90));
        loop assigns remainder;
        loop variant remainder;
     */
    while (remainder >= 10)
    {
        //@ assert remainder >= 10;
        remainder -= 10;
    }

    //@ assert remainder == n % 10;
    return (remainder == 9) || (n >= 90);
}
