#include <stdint.h>

/*@
    requires ((s) > 2 && (s) <= 100 &&
        (l) > 0 && (l) <= 100);
    ensures \result == ((s) * (l));
    assigns \nothing;
*/
uint32_t perimeter_polygon(uint32_t s, uint32_t l)
{
    // Variable declarations at top of scope
    uint32_t ret;

    //@ assert s * l <= 10000;
    ret = s * l;
    return ret;
}
