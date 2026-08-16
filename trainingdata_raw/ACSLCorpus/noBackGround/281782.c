#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> (((a) == (b) && (c) == (d)) || ((a) == (c) && (b) == (d)) || ((a) == (d) && (b) == (c)));
 */
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    bool result;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    //@ assert 1 <= d <= 100;

    if (a == b && c == d)
    {
        //@ assert a == b && c == d;
        result = true;
    }
    else if (a == c && b == d)
    {
        //@ assert a == c && b == d;
        result = true;
    }
    else if (a == d && b == c)
    {
        //@ assert a == d && b == c;
        result = true;
    }
    else
    {
        //@ assert !(a == b && c == d) && !(a == c && b == d) && !(a == d && b == c);
        result = false;
    }

    //@ assert result == true <==> (((a) == (b) && (c) == (d)) || ((a) == (c) && (b) == (d)) || ((a) == (d) && (b) == (c)));
    return result;
}
