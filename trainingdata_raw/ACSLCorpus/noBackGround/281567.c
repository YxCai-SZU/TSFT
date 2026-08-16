#include <stdint.h>

/*@
    requires (2 <= (a) <= 100 && 2 <= (b) <= 100);
    ensures \result == (((a) - 1) * ((b) - 1));
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    //@ assert a > 1;
    //@ assert b > 1;
    //@ assert (a - 1) * (b - 1) <= 99 * 99;
    return (a - 1) * (b - 1);
}
