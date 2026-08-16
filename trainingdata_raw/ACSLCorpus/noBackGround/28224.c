#include <stdint.h>
/*@
    requires ((s) > 0 && (s) <= INT32_MAX / 4);
    ensures \result == (4 * (s));
    ensures \result > 0;
    assigns \nothing;
*/
int32_t perimeter_square(int32_t s)
{
    //@ assert ((s) > 0 && (s) <= INT32_MAX / 4);
    //@ assert (4 * (s)) > 0;
    //@ assert (4 * (s)) <= INT32_MAX;
    return 4 * s;
}
