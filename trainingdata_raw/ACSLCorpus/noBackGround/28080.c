#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 1000000000);
    ensures \result >= 0;
    ensures \result <= (((x) / 11) * 2 + 2);
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t ans = 0;
    int64_t temp = x;
    int64_t div = 0;
    int64_t rem = x;
    
    /*@
        loop invariant 1 <= x && x <= 1000000000;
        loop invariant 0 <= div;
        loop invariant div <= x / 11;
        loop invariant rem == x - div * 11;
        loop assigns div, rem;
        loop variant rem;
    */
    while (rem >= 11)
    {
        rem -= 11;
        div += 1;
    }
    
    ans += div * 2;
    temp = rem;
    
    //@ assert temp == x - div * 11;
    
    if (temp > 6)
    {
        ans += 2;
    }
    else if (temp > 0)
    {
        ans += 1;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= (((x) / 11) * 2 + 2);
    
    return ans;
}
