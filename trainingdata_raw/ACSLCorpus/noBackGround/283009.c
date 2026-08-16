#include <stdbool.h>

/*@
    requires 0 <= x <= 8;
    requires 0 <= y <= 8;
    ensures \result == (x * y <= 1000);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y, unsigned int z)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int product;

    //@ assert (0 <= (x) <= 8 && 0 <= (y) <= 8);
    //@ assert x * y <= 64;
    //@ assert x * y <= 100;
    //@ assert x * y <= 1000;

    product = x * y;
    result = product <= 1000;
    return result;
}
