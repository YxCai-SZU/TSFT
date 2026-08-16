#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9);
    requires (1 <= (b) <= 9);
    requires (1 <= (c) <= 9);
    ensures \result >= 10;
    ensures \result <= 999;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int res;

    res = a;

    if (b > a)
    {
        //@ assert b > a;
        res = res * 10 + b;
    }
    else
    {
        //@ assert b <= a;
        res = res * 100 + b * 10 + c;
    }

    //@ assert res >= 10 && res <= 999;
    return res;
}
