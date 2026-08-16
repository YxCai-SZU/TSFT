#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    requires a != b && b != c && a != c;
    ensures \result == true <==> (((a) <= (c) && (c) <= (b)) || ((b) <= (c) && (c) <= (a)));
*/
bool func(int a, int b, int c)
{
    bool result = false;

    //@ assert a != b && b != c && a != c;
    //@ assert 0 <= a <= 100 && 0 <= b <= 100 && 0 <= c <= 100;

    if (a < b)
    {
        //@ assert a < b;
        if (c >= a && c <= b)
        {
            result = true;
        }
        //@ assert result == true <==> (c >= a && c <= b);
    }
    else
    {
        //@ assert a >= b;
        if (c <= a && c >= b)
        {
            result = true;
        }
        //@ assert result == true <==> (c <= a && c >= b);
    }

    //@ assert result == true <==> (((a) <= (c) && (c) <= (b)) || ((b) <= (c) && (c) <= (a)));
    return result;
}
