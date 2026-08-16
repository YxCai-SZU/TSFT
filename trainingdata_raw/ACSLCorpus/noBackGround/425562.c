#include <stdint.h>

/*@
    requires (1 <= (n) <= 1000000 &&
        1 <= (k) <= (n) &&
        1 <= (a) <= 1000000000);
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t k, int64_t a)
{
    int64_t ans = 0;
    int64_t i = 0;
    int64_t j = 0;
    int64_t a1 = 0;
    int64_t b1 = 0;
    int64_t a2 = 0;
    int64_t b2 = 0;

    //@ assert (1 <= (n) <= 1000000 &&         1 <= (k) <= (n) &&         1 <= (a) <= 1000000000);

    if (k == 1)
    {
        ans = 1;
    }
    else
    {
        //@ assert 1 <= n <= 1000000;
        //@ assert 1 <= k <= n;
        //@ assert 1 <= a <= 1000000000;

        a1 = a - (k - 1);
        if (a1 < 0)
        {
            a1 = 0;
        }

        b1 = k - 2;
        if (b1 < 0)
        {
            b1 = 0;
        }

        a2 = n - a - (k - 1);
        if (a2 < 0)
        {
            a2 = 0;
        }

        b2 = k - 2;
        if (b2 < 0)
        {
            b2 = 0;
        }

        //@ assert a1 == ((a) - ((k) - 1) < 0 ? 0 : (a) - ((k) - 1));
        //@ assert b1 == ((k) - 2 < 0 ? 0 : (k) - 2);
        //@ assert a2 == ((n) - (a) - ((k) - 1) < 0 ? 0 : (n) - (a) - ((k) - 1));
        //@ assert b2 == ((k) - 2 < 0 ? 0 : (k) - 2);

        if (a1 * 2 < b1 + 1)
        {
            i = a1 * 2;
        }
        else
        {
            i = b1 + 1;
        }

        if (a2 * 2 < b2 + 1)
        {
            j = a2 * 2;
        }
        else
        {
            j = b2 + 1;
        }

        //@ assert i == ((a1) * 2 < (b1) + 1 ? (a1) * 2 : (b1) + 1);
        //@ assert j == ((a2) * 2 < (b2) + 1 ? (a2) * 2 : (b2) + 1);

        if (i + j < k)
        {
            ans = i + j;
        }
        else
        {
            ans = k - 1;
        }

        //@ assert ans == ((i) + (j) < (k) ? (i) + (j) : (k) - 1);
    }

    //@ assert ans >= 0;
    return ans;
}
