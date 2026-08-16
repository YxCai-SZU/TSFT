#include <stdint.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    ensures \result <= n * a;
    ensures \result <= b;
    ensures \result >= 0;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t a, uint32_t b)
{
    uint32_t ans;

    //@ assert n * a <= 1000;

    if (n * a < b)
    {
        ans = n * a;
        //@ assert ans == n * a;
    }
    else
    {
        ans = b;
        //@ assert ans == b;
    }

    return ans;
}
