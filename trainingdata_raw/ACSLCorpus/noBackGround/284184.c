#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t c;
    
    //@ assert (1 <= (a) && (a) <= 10000);
    //@ assert (1 <= (b) && (b) <= 10000);
    //@ assert ((a) * (b)) <= 10000 * 10000;
    
    c = a * b;
    return (int32_t)c;
}
