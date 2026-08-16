#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 10);
    ensures \result == ((n) + (n) * (n) + (n) * (n) * (n));
    assigns \nothing;
*/
int32_t func(int32_t n)
{
    uint32_t n_unsigned;
    uint32_t result_unsigned;
    
    //@ assert (1 <= (n) && (n) <= 10);
    
    if (n < 0) {
        n_unsigned = (uint32_t)(-n);
    } else {
        n_unsigned = (uint32_t)n;
    }
    
    //@ assert 1 <= n_unsigned && n_unsigned <= 10;
    
    result_unsigned = n_unsigned + n_unsigned * n_unsigned + n_unsigned * n_unsigned * n_unsigned;
    
    //@ assert result_unsigned == ((n_unsigned) + (n_unsigned) * (n_unsigned) + (n_unsigned) * (n_unsigned) * (n_unsigned));
    
    if (n < 0) {
        return -(int32_t)result_unsigned;
    } else {
        return (int32_t)result_unsigned;
    }
}
