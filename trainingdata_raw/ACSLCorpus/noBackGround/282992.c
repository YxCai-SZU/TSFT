#include <stdint.h>

/*@
    requires ((n) < 0x80000000);
    ensures \result == ((n) + 1);
    ensures \result > n;
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    //@ assert ((n) < 0x80000000);
    
    // Proof block for overflow safety
    //@ assert n < 0x80000000;
    //@ assert n + 1 < 0x80000000 + 1;
    
    return n + 1;
}
