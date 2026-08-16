#include <stdint.h>

/*@
    requires (2 <= (a) <= 100);
    requires (2 <= (b) <= 100);
    ensures \result == (((a) - 1) * ((b) - 1));
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b)
{
    // Declare all variables at the top
    int32_t result;

    //@ assert a - 1 >= 1;
    //@ assert b - 1 >= 1;
    //@ assert (a - 1) * (b - 1) >= 0;
    //@ assert (a - 1) * (b - 1) <= 99 * 99;
    //@ assert (a - 1) * (b - 1) <= 2147483647;

    result = (a - 1) * (b - 1);
    return result;
}
