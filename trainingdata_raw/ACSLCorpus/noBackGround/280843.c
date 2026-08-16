#include <limits.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result >= 0;
    ensures \result <= a + b + c + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int min_ab;
    int min_cd;
    int min_ab_cd;
    int ans;

    //@ assert a >= 1 && a <= 10000;
    //@ assert b >= 1 && b <= 10000;
    //@ assert c >= 1 && c <= 10000;
    //@ assert d >= 1 && d <= 10000;

    if (a < b)
    {
        min_ab = a;
    }
    else
    {
        min_ab = b;
    }

    //@ assert (((a) <= (b) ==> (min_ab) == (a)) && ((a) > (b) ==> (min_ab) == (b)));

    if (c < d)
    {
        min_cd = c;
    }
    else
    {
        min_cd = d;
    }

    //@ assert (((c) <= (d) ==> (min_cd) == (c)) && ((c) > (d) ==> (min_cd) == (d)));

    if (min_ab < min_cd)
    {
        min_ab_cd = min_ab;
    }
    else
    {
        min_ab_cd = min_cd;
    }

    //@ assert (((min_ab) <= (min_cd) ==> (min_ab_cd) == (min_ab)) && ((min_ab) > (min_cd) ==> (min_ab_cd) == (min_cd)));

    ans = min_ab_cd * 2;
    if (a + b == min_ab * 2)
    {
        ans += 1;
    }
    if (c + d == min_cd * 2)
    {
        ans += 1;
    }

    //@ assert ans == ((((((a))) <= (((b))) ? (((a))) : (((b)))) <= ((((c))) <= (((d))) ? (((c))) : (((d)))) ? ((((a))) <= (((b))) ? (((a))) : (((b)))) : ((((c))) <= (((d))) ? (((c))) : (((d))))) * 2 +         ((a) + (b) == (((a)) <= ((b)) ? ((a)) : ((b))) * 2 ? 1 : 0) +         ((c) + (d) == (((c)) <= ((d)) ? ((c)) : ((d))) * 2 ? 1 : 0));
    //@ assert ans >= 0;
    //@ assert ans <= a + b + c + d;

    return ans;
}
