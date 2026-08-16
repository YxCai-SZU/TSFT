#include <stdbool.h>

/*@
    requires 1 <= a <= 10;
    requires 1 <= b <= 10;
    requires 1 <= c <= 10;
    requires 1 <= d <= 10;
    ensures \result == true <==> ((a) == (c) || (b) == (d) || ((a) == (d) && (c) == (b)));
 */
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    bool result = false;

    //@ assert a >= 1 && a <= 10;
    //@ assert b >= 1 && b <= 10;
    //@ assert c >= 1 && c <= 10;
    //@ assert d >= 1 && d <= 10;

    if (a == c)
    {
        result = true;
    }

    if (b == d)
    {
        result = true;
    }

    if (a == d && c == b)
    {
        result = true;
    }

    //@ assert result == true <==> ((a) == (c) || (b) == (d) || ((a) == (d) && (c) == (b)));
    return result;
}
