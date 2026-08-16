#include <stdbool.h>

/*@
    requires a <= b;
    requires a >= -100;
    requires b <= 100;
    ensures \result == (c >= a && c <= b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool result;

    //@ assert a <= b;
    //@ assert a >= -100;
    //@ assert b <= 100;

    if (c >= a && c <= b)
    {
        //@ assert ((a) <= (b) && (c) >= (a) && (c) <= (b));
        result = true;
    }
    else
    {
        //@ assert !((a) <= (b) && (c) >= (a) && (c) <= (b));
        result = false;
    }

    return result;
}
