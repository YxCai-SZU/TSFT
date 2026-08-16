#include <stdint.h>

/*@
    requires (1 <= (A) <= 100 && 1 <= (B) <= 100);
    ensures \result == ((A) * (B));
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t B)
{
    //@ assert (1 <= (A) <= 100 && 1 <= (B) <= 100);
    //@ assert ((A) * (B)) <= 10000;
    return A * B;
}
