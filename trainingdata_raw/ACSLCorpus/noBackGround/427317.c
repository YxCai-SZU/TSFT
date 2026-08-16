#include <stdint.h>

/*@
    requires (0 <= (a) && (a) < 100 && 0 <= (b) && (b) < 100);
    ensures \result >= ((a) * (b));
    ensures \result <= ((a) * (b)) + 1;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b)
{
    //@ assert (0 <= (a) && (a) < 100 && 0 <= (b) && (b) < 100);
    
    //@ assert ((a) * (b)) <= 10000;
    
    uint64_t product = a * b;
    uint64_t res = product + 1;
    
    //@ assert res >= ((a) * (b));
    //@ assert res <= ((a) * (b)) + 1;
    
    return res;
}
