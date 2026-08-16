#include <stdint.h>

/*@ requires (2 <= (a) <= 100) && (2 <= (b) <= 100); 
    ensures \result == (((a) - 1) * ((b) - 1)); */
int32_t func(int32_t a, int32_t b)
{
    int32_t result;
    
    //@ assert a - 1 >= 1;
    //@ assert b - 1 >= 1;
    //@ assert (a - 1) * (b - 1) <= 99 * 99;
    
    result = (a - 1) * (b - 1);
    return result;
}
