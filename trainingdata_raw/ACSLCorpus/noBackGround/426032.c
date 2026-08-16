#include <stdint.h>

/*@
    requires ((A) <= 8 && (B) <= 8 && (C) <= 8);
    ensures \result == A * B * C;
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t B, uint32_t C)
{
    //@ assert A * B <= 64;
    //@ assert A * B * C <= 512;
    return A * B * C;
}
