#include <limits.h>

/*@
    requires (-100 <= (a) <= 100 && -100 <= (b) <= 100 && -100 <= (c) <= 100 && -100 <= (d) <= 100);
    ensures ((\result) == (a) || (\result) == (b) || (\result) == (c) || (\result) == (d) ||
        (\result) == (a) + (b) || (\result) == (a) + (c) || (\result) == (a) + (d) ||
        (\result) == (b) + (c) || (\result) == (b) + (d) || (\result) == (c) + (d) ||
        (\result) == (a) + (b) + (c) || (\result) == (a) + (b) + (d) || (\result) == (a) + (c) + (d) ||
        (\result) == (b) + (c) + (d) || (\result) == (a) + (b) + (c) + (d));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_bc;
    int max_cd;
    int max_abc;
    int max_bcd;
    int max_abcd;
    int ans;

    //@ assert (-100 <= (a) <= 100 && -100 <= (b) <= 100 && -100 <= (c) <= 100 && -100 <= (d) <= 100);

    if (a > b)
    {
        max_ab = a;
    }
    else
    {
        max_ab = b;
    }

    if (b > c)
    {
        max_bc = b;
    }
    else
    {
        max_bc = c;
    }

    if (c > d)
    {
        max_cd = c;
    }
    else
    {
        max_cd = d;
    }

    if (max_ab > c)
    {
        max_abc = max_ab;
    }
    else
    {
        max_abc = c;
    }

    if (max_bc > d)
    {
        max_bcd = max_bc;
    }
    else
    {
        max_bcd = d;
    }

    if (max_abc > d)
    {
        max_abcd = max_abc;
    }
    else
    {
        max_abcd = d;
    }

    ans = max_abcd;

    //@ assert ((ans) == (a) || (ans) == (b) || (ans) == (c) || (ans) == (d) ||         (ans) == (a) + (b) || (ans) == (a) + (c) || (ans) == (a) + (d) ||         (ans) == (b) + (c) || (ans) == (b) + (d) || (ans) == (c) + (d) ||         (ans) == (a) + (b) + (c) || (ans) == (a) + (b) + (d) || (ans) == (a) + (c) + (d) ||         (ans) == (b) + (c) + (d) || (ans) == (a) + (b) + (c) + (d));

    return ans;
}
