#include <stdbool.h>

/*@
    requires (1 <= (x) && (x) <= 100) && (1 <= (y) && (y) <= 100) && (1 <= (z) && (z) <= 100);
    requires ((x) + (y) + (z) <= 100);
    ensures \result == true <==> ((((x)) + ((y)) + ((z))) == 100 &&
        (((x) == (y) && (y) == (z)) || ((x) == (z)) || ((y) == (z))));
    assigns \nothing;
*/
bool func(long x, long y, long z)
{
    // Variable declarations at top of scope
    bool result = false;
    
    //@ assert (1 <= (x) && (x) <= 100);
    //@ assert (1 <= (y) && (y) <= 100);
    //@ assert (1 <= (z) && (z) <= 100);
    //@ assert ((x) + (y) + (z) <= 100);
    //@ assert ((x) + (y) + (z)) >= 3;
    
    if (x + y + z != 100) {
        result = false;
    } else if (x == y && y == z) {
        result = true;
    } else if (x == z || y == z) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
