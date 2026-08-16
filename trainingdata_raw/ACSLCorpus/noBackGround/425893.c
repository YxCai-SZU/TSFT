#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == 1 || \result == 0 || \result == 2;
    ensures \result == 1 ==> ((a) > (b) && (b) > (c) && (c) > (d));
    ensures \result == 0 ==> ((a) <= (b) || (b) <= (c) || (c) <= (d));
    ensures \result == 2 ==> ((a) < (b) && (b) < (c) && (c) < (d));
*/
int func(int a, int b, int c, int d)
{
    int res = 0;

    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    //@ assert 1 <= c <= 10000;
    //@ assert 1 <= d <= 10000;

    if (a < b && b < c && c < d)
    {
        res = 2;
        //@ assert ((a) < (b) && (b) < (c) && (c) < (d));
    }
    else if (a > b && b > c && c > d)
    {
        res = 1;
        //@ assert ((a) > (b) && (b) > (c) && (c) > (d));
    }
    else
    {
        res = 0;
        //@ assert ((a) <= (b) || (b) <= (c) || (c) <= (d));
    }

    //@ assert res == 1 || res == 0 || res == 2;
    return res;
}
