#include <stddef.h>

/*@
    requires 1 <= x && x <= 100;
    ensures \result <= 10 * (x / 11) + 10;
    ensures \result >= 0;
    assigns \nothing;
*/
size_t func(size_t x)
{
    size_t ans;

    ans = 10 * (x / 11);
    //@ assert ans == 10 * (x / 11);

    if (x % 11 != 0)
    {
        ans += 10;
        //@ assert ans == 10 * (x / 11) + 10;
    }
    else
    {
        //@ assert ans == 10 * (x / 11);
    }

    //@ assert ans <= 10 * (x / 11) + 10;
    //@ assert ((ans) >= 0);

    return ans;
}
