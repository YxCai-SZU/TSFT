#include <stdbool.h>

/*@
    requires ((a) <= (b) &&
        (a) >= -0x7FFFFFFF &&
        (b) <= 0x7FFFFFFF &&
        (c) >= -0x7FFFFFFF &&
        (c) <= 0x7FFFFFFF);
    ensures \result == (a <= c && c <= b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert a <= b;
    //@ assert a >= -0x7FFFFFFF;
    //@ assert b <= 0x7FFFFFFF;
    //@ assert c >= -0x7FFFFFFF;
    //@ assert c <= 0x7FFFFFFF;
    
    return a <= c && c <= b;
}
