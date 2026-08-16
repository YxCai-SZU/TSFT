#include <limits.h>

/*@
    requires ((x) > 0) && ((y) > 0) && ((z) > 0);
    requires ((((x)) > 0) && (((y)) > 0) && (((z)) > 0) &&
        (x) * (y) < INT_MAX / (z));
    ensures \result == x * y * z;
    assigns \nothing;
*/
int func(int x, int y, int z)
{
    // Variable declarations at top of scope
    int product;

    //@ assert ((x) > 0) && ((y) > 0) && ((z) > 0);
    //@ assert ((((x)) > 0) && (((y)) > 0) && (((z)) > 0) &&         (x) * (y) < INT_MAX / (z));
    //@ assert x * y * z <= INT_MAX;

    product = x * y * z;
    return product;
}
