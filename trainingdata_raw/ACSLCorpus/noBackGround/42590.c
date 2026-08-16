#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    ensures \result == true <==> ((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 0 <= a && a <= 100;
    //@ assert 0 <= b && b <= 100;
    //@ assert 0 <= c && c <= 100;

    if (a + b == c || a + c == b || b + c == a)
    {
        //@ assert ((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
        result = true;
    }
    else
    {
        //@ assert !((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
        result = false;
    }

    return result;
}
