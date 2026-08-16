#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (x) && (x) <= 100);
    ensures ((\result) == ((a) <= (x) && (a) + (b) >= (x)));
    assigns \nothing;
*/
bool func(long a, long b, long x)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100 &&         1 <= (x) && (x) <= 100);

    if (a > x || a + b < x) {
        //@ assert a > x || a + b < x;
        result = false;
    } else {
        //@ assert a <= x && a + b >= x;
        result = true;
    }

    //@ assert ((result) == ((a) <= (x) && (a) + (b) >= (x)));
    return result;
}
