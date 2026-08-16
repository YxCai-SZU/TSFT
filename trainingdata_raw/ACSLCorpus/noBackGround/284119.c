#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - ((n) / 15) * 200);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t ans = 0;
    uint32_t i = 1;

    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert ans == 0;
    //@ assert i == 1;

    /*@
        loop invariant 1 <= i && i <= n + 1;
        loop invariant ans == (((i) - 1) * 800);
        loop invariant (1 <= (n) && (n) <= 100);
        loop assigns ans, i;
        loop variant n - i + 1;
    */
    while (i <= n)
    {
        ans += 800;
        i += 1;
        //@ assert ans == (((i) - 1) * 800);
    }

    i = 1;
    //@ assert i == 1;

    /*@
        loop invariant 1 <= i && i <= n/15 + 1;
        loop invariant ans == ((n) * 800 - ((i) - 1) * 200);
        loop invariant (1 <= (n) && (n) <= 100);
        loop assigns ans, i;
        loop variant n/15 - i + 1;
    */
    while (i <= n / 15)
    {
        ans -= 200;
        i += 1;
        //@ assert ans == ((n) * 800 - ((i) - 1) * 200);
    }

    //@ assert ans == ((n) * 800 - ((n) / 15) * 200);
    return ans;
}
