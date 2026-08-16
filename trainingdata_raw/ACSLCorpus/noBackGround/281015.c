#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * 314159 * (r) / 100000);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t ans;
    int64_t quotient;
    int64_t remainder;
    
    pi = 314159;
    ans = 2 * r * pi;
    quotient = 0;
    remainder = ans;
    
    /*@
        loop invariant (1 <= (r) <= 100);
        loop invariant ((pi) == 314159);
        loop invariant ((ans) == 2 * (r) * (pi));
        loop invariant ((quotient) * 100000 + (remainder) == (ans));
        loop invariant ((quotient) >= 0);
        loop invariant ((remainder) >= 0);
        loop invariant ((quotient) <= 2 * 314159 * 100);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 100000)
    {
        //@ assert remainder >= 100000;
        quotient = quotient + 1;
        remainder = remainder - 100000;
    }
    
    ans = quotient;
    return ans;
}
