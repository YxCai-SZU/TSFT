#include <stdint.h>

/*@
    requires (-1000 <= (a) <= 1000 &&
        -1000 <= (b) <= 1000 &&
        (a) <= (b));
    ensures \result == ((b) - (a));
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t result;

    //@ assert (-1000 <= (a) <= 1000 &&         -1000 <= (b) <= 1000 &&         (a) <= (b));
    //@ assert a >= -1000 && a <= 1000;
    //@ assert b >= -1000 && b <= 1000;
    //@ assert a <= b;
    //@ assert -1000 <= b - a <= 2000;
    //@ assert b - a == b - a;

    result = b - a;

    //@ assert result == ((b) - (a));
    return result;
}
