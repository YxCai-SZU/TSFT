#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == ((a) - (b) * 2) || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t ans;

    //@ assert ((a) - (b) * 2) <= 100;

    ans = a - b * 2;
    if (ans < 0)
    {
        ans = 0;
    }

    //@ assert ans >= 0;
    //@ assert ans == ((a) - (b) * 2) || ans == 0;

    return ans;
}
