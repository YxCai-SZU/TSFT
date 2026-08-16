#include <stdint.h>

/*@
    requires ((x) == 0 || (x) == 1);
    ensures \result == ((x) ^ 1);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    //@ assert ((x) == 0 || (x) == 1);
    return (x ^ 1);
}
