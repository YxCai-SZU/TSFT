#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> (((a) <= (c) && (c) <= (b)) ||
        ((a) <= (d) && (d) <= (b)) ||
        ((a) <= (c) && (c) <= (d) && (d) <= (b)) ||
        ((c) <= (a) && (a) <= (d)) ||
        ((c) <= (b) && (b) <= (d)));
 */
bool func(int a, int b, int c, int d)
{
    bool result;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    //@ assert 1 <= d <= 100;

    if (a <= c && c <= b)
    {
        //@ assert (((a) <= (c) && (c) <= (b)) ||         ((a) <= (d) && (d) <= (b)) ||         ((a) <= (c) && (c) <= (d) && (d) <= (b)) ||         ((c) <= (a) && (a) <= (d)) ||         ((c) <= (b) && (b) <= (d)));
        result = true;
    }
    else if (a <= d && d <= b)
    {
        //@ assert (((a) <= (c) && (c) <= (b)) ||         ((a) <= (d) && (d) <= (b)) ||         ((a) <= (c) && (c) <= (d) && (d) <= (b)) ||         ((c) <= (a) && (a) <= (d)) ||         ((c) <= (b) && (b) <= (d)));
        result = true;
    }
    else if (a <= c && c <= d && d <= b)
    {
        //@ assert (((a) <= (c) && (c) <= (b)) ||         ((a) <= (d) && (d) <= (b)) ||         ((a) <= (c) && (c) <= (d) && (d) <= (b)) ||         ((c) <= (a) && (a) <= (d)) ||         ((c) <= (b) && (b) <= (d)));
        result = true;
    }
    else if (c <= a && a <= d)
    {
        //@ assert (((a) <= (c) && (c) <= (b)) ||         ((a) <= (d) && (d) <= (b)) ||         ((a) <= (c) && (c) <= (d) && (d) <= (b)) ||         ((c) <= (a) && (a) <= (d)) ||         ((c) <= (b) && (b) <= (d)));
        result = true;
    }
    else if (c <= b && b <= d)
    {
        //@ assert (((a) <= (c) && (c) <= (b)) ||         ((a) <= (d) && (d) <= (b)) ||         ((a) <= (c) && (c) <= (d) && (d) <= (b)) ||         ((c) <= (a) && (a) <= (d)) ||         ((c) <= (b) && (b) <= (d)));
        result = true;
    }
    else
    {
        //@ assert !(((a) <= (c) && (c) <= (b)) ||         ((a) <= (d) && (d) <= (b)) ||         ((a) <= (c) && (c) <= (d) && (d) <= (b)) ||         ((c) <= (a) && (a) <= (d)) ||         ((c) <= (b) && (b) <= (d)));
        result = false;
    }

    return result;
}
