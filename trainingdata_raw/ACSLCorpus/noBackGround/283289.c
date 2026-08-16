#include <limits.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    requires -100 <= d <= 100;
    ensures \result == a || \result == b || \result == c || \result == d;
    ensures \result >= a || \result >= b || \result >= c || \result >= d;
*/
int func(int a, int b, int c, int d)
{
    int max_val;
    int res;

    max_val = a;
    //@ assert max_val == a;
    if (b > max_val)
    {
        max_val = b;
    }
    //@ assert max_val >= a && max_val >= b;
    if (c > max_val)
    {
        max_val = c;
    }
    //@ assert max_val >= a && max_val >= b && max_val >= c;
    if (d > max_val)
    {
        max_val = d;
    }
    //@ assert max_val >= a && max_val >= b && max_val >= c && max_val >= d;

    res = a;
    //@ assert res == a;
    if (res < max_val)
    {
        res = max_val;
    }
    //@ assert res >= a;
    if (b < res)
    {
        res = b;
    }
    //@ assert ((res) == (a) || (res) == (b) || (res) == (max_val) || (res) == (max_val));
    if (c < res)
    {
        res = c;
    }
    //@ assert ((res) == (a) || (res) == (b) || (res) == (c) || (res) == (max_val));
    if (d < res)
    {
        res = d;
    }
    //@ assert ((res) == (a) || (res) == (b) || (res) == (c) || (res) == (d));
    //@ assert ((res) >= (a) || (res) >= (b) || (res) >= (c) || (res) >= (d));

    return res;
}
