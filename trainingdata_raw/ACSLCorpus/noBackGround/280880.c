#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100);
    requires (0 <= (b) && (b) <= (a) * (a));
    ensures \result == ((a) * (a) - (b));
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b)
{
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (0 <= (b) && (b) <= (a) * (a));
    //@ assert a * a <= 10000;
    //@ assert a * a - b >= 0;
    return a * a - b;
}
