#include <stdint.h>

/*@ requires 1 <= n <= 10000;
    ensures \result >= 0;
    ensures \result < 1000;
    ensures \result == ((1000 - (n) % 1000) % 1000);
    assigns \nothing;
 */
int32_t func(int32_t n)
{
    uint32_t n_unsigned;
    uint32_t result_unsigned;
    int32_t result;
    
    //@ assert 1 <= n <= 10000;
    
    if (n < 0) {
        n_unsigned = (uint32_t)(-n);
    } else {
        n_unsigned = (uint32_t)n;
    }
    
    result_unsigned = (1000 - n_unsigned % 1000) % 1000;
    
    if (n < 0) {
        result = -(int32_t)result_unsigned;
    } else {
        result = (int32_t)result_unsigned;
    }
    
    //@ assert result >= 0;
    //@ assert result < 1000;
    //@ assert result == ((1000 - (n) % 1000) % 1000);
    
    return result;
}
