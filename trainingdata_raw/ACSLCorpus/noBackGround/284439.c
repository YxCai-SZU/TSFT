#include <stdint.h>

/*@
    requires ((n) < 0x10000);
    ensures \result == ((n) * (n));
    ensures \result >= 0;
    assigns \nothing;
*/
uint32_t is_square(uint32_t n)
{
    //@ assert n >= 0 && n < 0x10000;
    //@ assert ((n) * (n)) < 0x100000000;
    
    return n * n;
}
