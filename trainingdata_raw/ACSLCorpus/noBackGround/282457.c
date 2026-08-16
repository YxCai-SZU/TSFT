#include <stdbool.h>

/*@
    requires (1 <= (n) <= 10000 && 1 <= (m) <= 10000);
    ensures \result == (n <= m * 10);
    assigns \nothing;
*/
bool func(int n, int m)
{
    int mochi;
    int ans;

    //@ assert 1 <= n <= 10000 && 1 <= m <= 10000;

    if (n % 10 == 0)
    {
        mochi = n / 10;
    }
    else
    {
        //@ assert n / 10 < 10000;
        mochi = n / 10 + 1;
    }

    if (m == 0)
    {
        if (mochi <= 0)
        {
            ans = 0;
        }
        else
        {
            ans = 1;
        }
    }
    else
    {
        if (mochi <= m)
        {
            ans = 0;
        }
        else
        {
            ans = 1;
        }
    }

    //@ assert ans == 0 ==> n <= m * 10;
    return ans == 0;
}
