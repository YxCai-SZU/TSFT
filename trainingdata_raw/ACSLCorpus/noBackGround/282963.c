#include <stdbool.h>

/*@
    requires a <= b;
    requires (-100 <= (a) <= 100);
    requires (-100 <= (b) <= 100);
    requires (-100 <= (c) <= 100);
    ensures \result == ((((c) >= (a) && (c) <= (b)) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert a <= b;
    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    //@ assert (-100 <= (c) <= 100);
    return c >= a && c <= b;
}
