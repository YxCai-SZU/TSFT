#include <limits.h>

/*@
    requires 1 <= n <= 100000;
    ensures \result >= 1 && \result <= n;
    ensures ((\result) == 1 || (\result) == 2 || (\result) == 4 || (\result) == 8 || (\result) == 16 || (\result) == 32 || (\result) == 64);
    assigns \nothing;
 */
int func(int n)
{
    int ans = 1;

    //@ assert ans == 1;
    if (n > 63)
    {
        ans = 64;
        //@ assert ans == 64;
    }
    else if (n > 31)
    {
        ans = 32;
        //@ assert ans == 32;
    }
    else if (n > 15)
    {
        ans = 16;
        //@ assert ans == 16;
    }
    else if (n > 7)
    {
        ans = 8;
        //@ assert ans == 8;
    }
    else if (n > 3)
    {
        ans = 4;
        //@ assert ans == 4;
    }
    else if (n > 1)
    {
        ans = 2;
        //@ assert ans == 2;
    }

    //@ assert ((ans) == 1 || (ans) == 2 || (ans) == 4 || (ans) == 8 || (ans) == 16 || (ans) == 32 || (ans) == 64);
    return ans;
}
