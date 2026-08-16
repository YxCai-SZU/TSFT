#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == (a - c <= d || a - b <= d);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    int x;
    int y;
    bool result;

    x = a - c;
    y = a - b;

    //@ assert -99 <= x <= 99;
    //@ assert -99 <= y <= 99;

    if (x <= d)
    {
        //@ assert x <= d;
        result = true;
    }
    else if (y <= d)
    {
        //@ assert y <= d;
        result = true;
    }
    else
    {
        //@ assert x > d && y > d;
        result = false;
    }

    //@ assert result == (x <= d || y <= d);
    return result;
}
