#include <stdint.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
uint32_t func(uint32_t r)
{
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert (3 * (r) * (r)) <= 30000;
    return 3 * r * r;
}
