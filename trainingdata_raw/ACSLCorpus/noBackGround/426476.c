#include <stdbool.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
    ensures \result == (c >= a && c <= b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert (-100 <= (c) <= 100);
    return c >= a && c <= b;
}
