#include <stdbool.h>

/*@
    requires 1 <= a <= 10;
    requires 1 <= b <= 10;
    requires 1 <= c <= 10;
    ensures \result == (a == b + c || b == a + c || c == a + b);
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    bool result;

    //@ assert 1 <= a <= 10;
    //@ assert 1 <= b <= 10;
    //@ assert 1 <= c <= 10;

    if (a == b + c || b == a + c || c == a + b)
    {
        result = true;
        //@ assert ((a) == (b) + (c) || (b) == (a) + (c) || (c) == (a) + (b));
    }
    else
    {
        result = false;
        //@ assert !((a) == (b) + (c) || (b) == (a) + (c) || (c) == (a) + (b));
    }

    return result;
}
