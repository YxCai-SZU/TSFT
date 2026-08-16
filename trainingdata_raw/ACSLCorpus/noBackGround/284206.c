#include <stdbool.h>

/*@
    requires ((a) >= 1 && (b) <= 10000 &&
        (c) >= 1 && (d) <= 10000 &&
        (a) <= (b) && (c) <= (d));
    ensures \result == (b < c || a < d);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    //@ assert a >= 1 && a <= 10000;
    //@ assert b >= 1 && b <= 10000;
    //@ assert c >= 1 && c <= 10000;
    //@ assert d >= 1 && d <= 10000;
    //@ assert a <= b;
    //@ assert c <= d;
    
    return b < c || a < d;
}
