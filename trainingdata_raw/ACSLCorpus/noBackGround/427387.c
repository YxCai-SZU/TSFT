#include <stdint.h>

/*@
    requires ((n) >= 0 && (n) <= 65535);
    ensures \result == ((n) * (n));
    assigns \nothing;
*/
uint32_t square_number(uint32_t n)
{
    uint32_t ret;
    
    //@ assert ((n) >= 0 && (n) <= 65535);
    //@ assert ((n) * (n)) <= 0xFFFFFFFFU;
    
    ret = n * n;
    
    //@ assert ret == ((n) * (n));
    return ret;
}
