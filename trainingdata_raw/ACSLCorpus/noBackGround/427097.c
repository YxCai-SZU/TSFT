#include <stdbool.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (d) >= 0);
    ensures \result == (a < b && b < c && c < d);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    //@ assert ((a) >= 0 && (b) >= 0 && (c) >= 0 && (d) >= 0);
    return a < b && b < c && c < d;
}
