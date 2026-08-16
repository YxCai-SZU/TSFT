#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> (((c) == (a) && (d) >= (b)) ||
        ((a) >= (c) && (b) == (d)) ||
        ((a) >= (c) && (d) >= (b)) ||
        ((a) == (c) && (b) >= (d)));
 */
bool func(int a, int b, int c, int d)
{
    int state = 0;

    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && 1 <= d <= 100;

    if (c == a)
    {
        state = 1;
    }

    if (d >= b)
    {
        state += 1;
    }

    if (state == 2)
    {
        //@ assert (((c) == (a) && (d) >= (b)) ||         ((a) >= (c) && (b) == (d)) ||         ((a) >= (c) && (d) >= (b)) ||         ((a) == (c) && (b) >= (d)));
        return true;
    }
    else
    {
        if (a >= c && b == d)
        {
            //@ assert (((c) == (a) && (d) >= (b)) ||         ((a) >= (c) && (b) == (d)) ||         ((a) >= (c) && (d) >= (b)) ||         ((a) == (c) && (b) >= (d)));
            return true;
        }
        else if (a >= c && d >= b)
        {
            //@ assert (((c) == (a) && (d) >= (b)) ||         ((a) >= (c) && (b) == (d)) ||         ((a) >= (c) && (d) >= (b)) ||         ((a) == (c) && (b) >= (d)));
            return true;
        }
        else if (a == c && b >= d)
        {
            //@ assert (((c) == (a) && (d) >= (b)) ||         ((a) >= (c) && (b) == (d)) ||         ((a) >= (c) && (d) >= (b)) ||         ((a) == (c) && (b) >= (d)));
            return true;
        }
        else
        {
            //@ assert !(((c) == (a) && (d) >= (b)) ||         ((a) >= (c) && (b) == (d)) ||         ((a) >= (c) && (d) >= (b)) ||         ((a) == (c) && (b) >= (d)));
            return false;
        }
    }
}
