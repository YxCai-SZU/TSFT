#include <stddef.h>

/*@
    requires (2 <= (a) && (a) <= 100 &&
        2 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b) - ((a) + (b) - 1));
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    // Variable declarations at top of scope
    size_t result;

    //@ assert (2 <= (a) && (a) <= 100 &&         2 <= (b) && (b) <= 100);
    //@ assert a * b >= a + b - 1;
    //@ assert a + b - 1 <= 100 + 100 - 1;
    //@ assert a * b <= 100 * 100;

    result = a * b - (a + b - 1);
    //@ assert result == ((a) * (b) - ((a) + (b) - 1));
    return result;
}
