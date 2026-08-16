#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 20) && (1 <= (b) && (b) <= 20);
    ensures \result == a * b;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    //@ assert (1 <= (a) && (a) <= 20);
    //@ assert (1 <= (b) && (b) <= 20);
    //@ assert a * b <= 400;
    return a * b;
}
