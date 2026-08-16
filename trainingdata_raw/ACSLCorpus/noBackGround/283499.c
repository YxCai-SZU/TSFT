#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures ((\result == 0 && n % 1000 == 0) || (\result == 1000 - n % 1000));
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    uint64_t n_unsigned;
    uint64_t remainder;
    uint64_t result;
    int64_t result_signed;

    //@ assert (1 <= (n) && (n) <= 10000);
    
    if (n < 0) {
        n_unsigned = (uint64_t)(-n);
    } else {
        n_unsigned = (uint64_t)n;
    }
    
    remainder = n_unsigned % 1000;
    
    if (remainder == 0) {
        result = 0;
    } else {
        result = 1000 - remainder;
    }
    
    //@ assert remainder == (uint64_t)(n % 1000);
    
    if (n < 0) {
        result_signed = -(int64_t)result;
    } else {
        result_signed = (int64_t)result;
    }
    
    //@ assert (result == 0 && n % 1000 == 0) || (result == 1000 - (n % 1000));
    
    return result_signed;
}
