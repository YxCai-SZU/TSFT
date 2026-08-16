#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    requires (1 <= (d) <= 100);
    ensures \result == b - a - d + c || \result == 0;
    ensures \result >= 0;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at scope top
    int ans;
    int tmp1;
    int tmp2;

    //@ assert b - a >= -99;
    //@ assert c - d >= -99;

    tmp1 = b - a;
    tmp2 = tmp1 - d;
    ans = tmp2 + c;

    if (ans < 0)
    {
        ans = 0;
    }

    //@ assert ans >= 0;
    return ans;
}
