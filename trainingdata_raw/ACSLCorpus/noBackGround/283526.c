#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
    ensures \result >= 0;
    ensures \result <= a * 3 + p;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t p)
{
    int64_t ans;
    int64_t i;

    ans = a * 3 + p;
    i = 0;

    /*@
        loop invariant 0 <= i <= 100;
        loop invariant 0 <= ans <= a * 3 + p;
        loop invariant (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
        loop assigns ans, i;
        loop variant ans;
    */
    while (i < 100)
    {
        if (ans >= 2)
        {
            ans -= 2;
        }
        else
        {
            break;
        }
        i += 1;
    }

    //@ assert ans >= 0;
    return ans;
}
