#include <stdbool.h>

/*@
    requires ((a) >= 0) && ((b) >= 0) && ((c) >= 0);
    requires ((k) >= 1);
    requires ((k) <= (a) + (b) + (c)) && ((k) <= 2000000000);
    ensures \result <= a;
*/
long func(long a, long b, long c, long k)
{
    long cnt;
    long ans;
    bool is_negative;

    cnt = k;
    ans = 0;
    is_negative = false;

    //@ assert cnt == k && ans == 0 && is_negative == false;

    if (cnt < 0)
    {
        cnt = -cnt;
        is_negative = true;
    }

    //@ assert cnt >= 0;

    if (cnt > a)
    {
        ans += a;
        cnt -= a;
        //@ assert ans == a && cnt == k - a;
    }
    else
    {
        ans += cnt;
        //@ assert ans == cnt && ans <= a;
        return ans;
    }

    //@ assert ans == a && cnt >= 0;

    if (cnt > b)
    {
        cnt -= b;
        //@ assert cnt == k - a - b;
    }
    else
    {
        //@ assert cnt <= b;
        return ans;
    }

    //@ assert ans == a && cnt >= 0;

    if (cnt > c)
    {
        ans -= c;
        //@ assert ans == a - c;
    }
    else
    {
        ans -= cnt;
        //@ assert ans == a - cnt;
    }

    //@ assert ans <= a;

    if (is_negative)
    {
        ans = -ans;
    }

    //@ assert ans <= a;
    return ans;
}
