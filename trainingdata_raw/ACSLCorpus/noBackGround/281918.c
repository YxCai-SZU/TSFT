#include <limits.h>

/*@
    requires (1 <= (a) <= 123);
    requires (1 <= (b) <= 123);
    requires (1 <= (c) <= 123);
    requires (1 <= (d) <= 123);
    requires (1 <= (e) <= 123);
    ensures \result >= 0;
    ensures \result <= 5;
    assigns \nothing;
*/
int func(int a, int b, int c, int d, int e)
{
    int res = 0;

    //@ assert res == 0;

    if (a < b)
    {
        res = res + 1;
    }

    //@ assert res >= 0 && res <= 1;

    if (a < c)
    {
        res = res + 1;
    }

    //@ assert res >= 0 && res <= 2;

    if (a < d)
    {
        res = res + 1;
    }

    //@ assert res >= 0 && res <= 3;

    if (a < e)
    {
        res = res + 1;
    }

    //@ assert res >= 0 && res <= 4;

    return res;
}

/*@
    requires (1 <= (a) <= 123);
    requires (1 <= (b) <= 123);
    requires (1 <= (c) <= 123);
    requires (1 <= (d) <= 123);
    requires (1 <= (e) <= 123);
    ensures \result >= 0;
    ensures \result <= 5;
    assigns \nothing;
*/
int func2(int a, int b, int c, int d, int e)
{
    int res = 0;

    //@ assert res == 0;

    if (a < b)
    {
        res = res + 1;
    }

    //@ assert res >= 0 && res <= 1;

    if (a < c)
    {
        res = res + 1;
    }

    //@ assert res >= 0 && res <= 2;

    if (a < d)
    {
        res = res + 1;
    }

    //@ assert res >= 0 && res <= 3;

    if (a < e)
    {
        res = res + 1;
    }

    //@ assert res >= 0 && res <= 4;

    return res;
}
