#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 10);
    ensures \result == ((x) * (x));
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    //@ assert (1 <= (x) && (x) <= 10);
    //@ assert x * x <= 100;
    return x * x;
}
