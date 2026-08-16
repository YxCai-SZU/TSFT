#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (h) <= 100) && ((h) % 2 == 0);
    ensures \result == (((a) + (b)) * (h) / 2);
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t h)
{
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (h) <= 100);
    //@ assert ((h) % 2 == 0);
    
    //@ assert ((a) + (b) <= 200);
    //@ assert (((a) + (b)) * (h) <= 20000);
    //@ assert (((a) + (b)) * (h) / 2 <= 10000);
    
    uint64_t result = (a + b) * h / 2;
    //@ assert result == (((a) + (b)) * (h) / 2);
    return result;
}
