#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100 &&
        1 <= (k) && (k) <= 3);
    ensures \result >= -c;
    ensures \result <= a;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int ans = 0;
    int rst = k;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100 &&         1 <= (c) && (c) <= 100 &&         1 <= (k) && (k) <= 3);

    if (a >= rst)
    {
        ans += rst;
        rst -= rst;
    }
    else
    {
        ans += a;
        rst -= a;
    }

    //@ assert ans == (k <= a ? k : a);

    if (b >= rst)
    {
        rst -= rst;
    }
    else
    {
        rst -= b;
    }

    ans -= rst;

    //@ assert ans >= -c;
    //@ assert ans <= a;

    return ans;
}
