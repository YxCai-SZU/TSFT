#include <stdbool.h>

/*@
    requires (1 <= (l) && (l) <= 1000);
    ensures \result == (((l) * 3) / 3);
    assigns \nothing;
*/
int func(int l)
{
    int res;
    int quotient;
    int remainder;
    
    res = l * 3;
    quotient = 0;
    remainder = res;
    
    /*@
        loop invariant (1 <= (l) && (l) <= 1000 &&
        0 <= (quotient) &&
        0 <= (remainder) &&
        (remainder) == (res) - 3 * (quotient) &&
        (res) == (l) * 3);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 3)
    {
        //@ assert remainder == res - 3 * quotient;
        quotient += 1;
        remainder -= 3;
    }
    
    //@ assert remainder == res - 3 * quotient;
    return quotient;
}
