#include <stdint.h>

/*@ requires 1 <= x <= 1000000000 && 1 <= t <= 1000000000;
    ensures \result >= 0 && (\result == x - t || \result == 0);
*/
int32_t func(int32_t x, int32_t t)
{
    int32_t result;
    
    //@ assert ((x) >= 0);
    //@ assert ((t) >= 0);
    
    if (x - t > 0) {
        //@ assert x - t >= 0;
        result = x - t;
    } else {
        //@ assert 0 >= 0;
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == x - t || result == 0;
    return result;
}
