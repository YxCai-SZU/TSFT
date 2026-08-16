#include <stdint.h>

/*@
    requires (-100 <= (x) <= 100);
    ensures \result == ((x) * (x) * (x));
    assigns \nothing;
*/
int32_t cuber(int32_t x)
{
    // Variable declarations at top of scope
    int32_t ret;

    //@ assert -100 <= x <= 100;
    //@ assert -100 * 100 <= x * x <= 100 * 100;
    //@ assert -100 * 100 * 100 <= x * x * x <= 100 * 100 * 100;

    ret = x * x * x;
    return ret;
}
