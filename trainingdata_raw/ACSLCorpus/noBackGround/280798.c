#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures 0 <= \result && \result <= 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans = 0;

    //@ assert (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);

    if (a == b)
    {
        ans += 1;
        //@ assert ans == 1;
    }
    else
    {
        //@ assert ans == 0;
    }

    if (b == c)
    {
        ans += 1;
        //@ assert ans == (a == b ? 1 : 0) + 1;
    }

    if (c == a)
    {
        ans += 1;
        //@ assert ans == (((a) == (b) ? 1 : 0) + ((b) == (c) ? 1 : 0) + ((c) == (a) ? 1 : 0));
    }

    //@ assert ans == (((a) == (b) ? 1 : 0) + ((b) == (c) ? 1 : 0) + ((c) == (a) ? 1 : 0));
    //@ assert 0 <= ans && ans <= 3;

    return ans;
}
