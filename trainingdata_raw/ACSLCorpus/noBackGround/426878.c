#include <stdint.h>

/*@
    requires 0 <= a && a < 1000;
    ensures \result == a * a * a;
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    //@ assert a * a < 1000000;
    //@ assert a * a * a < 1000000000;
    return a * a * a;
}
