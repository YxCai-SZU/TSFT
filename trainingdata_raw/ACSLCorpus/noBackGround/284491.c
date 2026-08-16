#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == true <==> ((2*(x) <= (y) && (y) <= 4*(x) && (y) % 2 == 0) ||
        (4*(x) <= (y) && (y) <= 2*(x) && (y) % 2 == 0));
    assigns \nothing;
 */
bool func(unsigned long long x, unsigned long long y)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert x * 2 <= 200;
    //@ assert x * 4 <= 400;

    if ((x * 2 <= y && y <= x * 4 && y % 2 == 0) ||
        (x * 4 <= y && y <= x * 2 && y % 2 == 0)) {
        //@ assert ((2*(x) <= (y) && (y) <= 4*(x) && (y) % 2 == 0) ||         (4*(x) <= (y) && (y) <= 2*(x) && (y) % 2 == 0));
        result = true;
    } else {
        //@ assert !((2*(x) <= (y) && (y) <= 4*(x) && (y) % 2 == 0) ||         (4*(x) <= (y) && (y) <= 2*(x) && (y) % 2 == 0));
        result = false;
    }

    return result;
}
