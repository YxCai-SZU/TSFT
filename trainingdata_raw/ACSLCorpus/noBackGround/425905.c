#include <stdint.h>

/*@
    requires (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10);
    ensures \result == ((a) * (b) * (c));
    assigns \nothing;
*/
uint32_t test(uint32_t a, uint32_t b, uint32_t c)
{
    //@ assert (1 <= (a) <= 10);
    //@ assert (1 <= (b) <= 10);
    //@ assert (1 <= (c) <= 10);
    //@ assert 1 <= a * b <= 100;
    //@ assert 1 <= a * b * c <= 1000;
    
    return a * b * c;
}
