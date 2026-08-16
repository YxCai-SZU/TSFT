#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    requires (1 <= (b) <= 10);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    //@ assert (1 <= (a) <= 10);
    //@ assert (1 <= (b) <= 10);
    //@ assert ((a) * (b)) <= 100;
    
    uint32_t c;
    c = a * b;
    
    //@ assert c == ((a) * (b));
    return c;
}
