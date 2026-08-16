#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> ((a) == (b) + (c) || (b) == (a) + (c) || (c) == (a) + (b));
 */
bool func(int a, int b, int c)
{
    bool result;

    //@ assert 1 <= a && a <= 9;
    //@ assert 1 <= b && b <= 9;
    //@ assert 1 <= c && c <= 9;

    if (a == b + c || b == a + c || c == a + b)
    {
        //@ assert ((a) == (b) + (c) || (b) == (a) + (c) || (c) == (a) + (b));
        result = true;
    }
    else
    {
        //@ assert !((a) == (b) + (c) || (b) == (a) + (c) || (c) == (a) + (b));
        result = false;
    }

    return result;
}
