#include <stdint.h>

/*@
    requires (1 <= (n) <= 10000);
    ensures \result >= 0 && \result < 1000;
    ensures \result == 0 ==> n % 1000 == 0;
    ensures \result > 0 ==> n % 1000 + \result == 1000;
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    uint64_t n_unsigned;
    uint64_t remainder;
    int64_t result;
    
    //@ assert (1 <= (n) <= 10000);
    
    if (n < 0) {
        n_unsigned = (uint64_t)(n + 10000);
    } else {
        n_unsigned = (uint64_t)n;
    }
    
    remainder = n_unsigned % 1000;
    
    if (remainder == 0) {
        result = 0;
        //@ assert result == 0;
        //@ assert n % 1000 == 0;
        return result;
    } else {
        //@ assert remainder > 0 && remainder < 1000;
        result = 1000 - (int64_t)remainder;
        //@ assert result > 0;
        //@ assert n % 1000 + result == 1000;
        return result;
    }
}
