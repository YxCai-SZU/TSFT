#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 20 &&
        1 <= (b) && (b) <= 20);
    ensures \result == ((a) * (b)) - 1 || \result == ((a) * (b)) + 1;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    // Variable declarations at top
    int64_t x;
    int64_t result;

    //@ assert (1 <= (a) && (a) <= 20 &&         1 <= (b) && (b) <= 20);
    //@ assert 1 <= ((a) * (b)) <= 400;

    x = a * b;

    if (x >= 1)
    {
        //@ assert x - 1 == ((a) * (b)) - 1 || x - 1 == ((a) * (b)) + 1;
        result = x - 1;
    }
    else
    {
        //@ assert x + 1 == ((a) * (b)) - 1 || x + 1 == ((a) * (b)) + 1;
        result = x + 1;
    }

    //@ assert result == ((a) * (b)) - 1 || result == ((a) * (b)) + 1;
    return result;
}
