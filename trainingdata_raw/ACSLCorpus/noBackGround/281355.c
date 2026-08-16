#include <stdbool.h>

/*@
    requires a < 0x80000000;
    requires b < 0x80000000;
    requires c < 0x80000000;
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool result;

    //@ assert a < 0x80000000;
    //@ assert b < 0x80000000;
    //@ assert c < 0x80000000;

    if (a < b && b < c)
    {
        result = true;
        //@ assert ((a) < (b) && (b) < (c));
    }
    else
    {
        result = false;
        //@ assert !((a) < (b) && (b) < (c));
    }

    return result;
}
