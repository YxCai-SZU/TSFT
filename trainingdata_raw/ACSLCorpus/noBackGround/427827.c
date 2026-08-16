#include <stdint.h>

/*@
    requires (0 <= (k) <= 200 && (k) != 0);
    ensures \result >= 0;
    ensures \result <= 3 * k;
    assigns \nothing;
*/
int64_t func(int64_t k)
{
    int64_t ans;
    int64_t c;
    int64_t a;
    int64_t b;

    ans = 0;
    c = 0;
    a = 0;
    b = 0;

    if (k >= 0)
    {
        //@ assert 0 <= 3 * k <= 600;
        ans = 3 * k;
        c = 2 * k;
        a = k;
        b = k;
    }

    if (k >= -200 && k < 0)
    {
        //@ assert 0 <= -1 * k <= 200;
        ans = -1 * k;
        c = -1 * k;
        a = k;
        b = k;
    }

    if (k >= -100 && k < 0)
    {
        //@ assert 0 <= -2 * k <= 200;
        ans = -2 * k;
        c = -1 * k;
        a = k;
        b = k;
    }

    if (k >= -50 && k < 0)
    {
        //@ assert 0 <= -3 * k <= 200;
        ans = -3 * k;
        c = -1 * k;
        a = k;
        b = k;
    }

    //@ assert ans >= 0;
    return ans;
}
