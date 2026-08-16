#include <limits.h>

/*@
    requires (1 <= (aa) && (aa) <= 20 &&
        1 <= (bb) && (bb) <= 20 &&
        (aa) + (bb) <= (n) && (n) <= 20);
    ensures \result >= 0 && \result <= n;
    ensures \result == n - aa || \result == n - bb || \result == 0;
*/
int func(int n, int aa, int bb)
{
    int ans;

    //@ assert (1 <= (aa) && (aa) <= 20 &&         1 <= (bb) && (bb) <= 20 &&         (aa) + (bb) <= (n) && (n) <= 20);
    //@ assert aa + bb <= n;

    if (n - aa < n - bb)
    {
        ans = n - aa;
    }
    else
    {
        ans = n - bb;
    }

    //@ assert ans == n - aa || ans == n - bb;

    if (ans < 0)
    {
        //@ assert ans < 0;
        ans = 0;
    }
    else
    {
        //@ assert ans >= 0;
    }

    //@ assert ans >= 0 && ans <= n;
    //@ assert ans == n - aa || ans == n - bb || ans == 0;
    return ans;
}
