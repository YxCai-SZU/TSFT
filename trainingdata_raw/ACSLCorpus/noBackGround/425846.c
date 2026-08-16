#include <stdint.h>

/*@
    requires 1 <= a && a <= b && b <= 100;
    ensures \result == (((b) - (a) + 1) * ((a) + (b)) / 2 - (b));
    assigns \nothing;
*/
int64_t func(uint64_t a, uint64_t b)
{
    //@ assert b - a + 1 <= 100;
    //@ assert a + b <= 200;
    //@ assert (b - a + 1) * (a + b) <= 20000;
    
    uint64_t sum;
    int64_t result;
    
    sum = (b - a + 1) * (a + b) / 2;
    result = (int64_t)sum - (int64_t)b;
    
    return result;
}
