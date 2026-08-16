#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 10000;
    
    logic integer compute_result(integer n) =
        n % 1000 == 0 ? 0 : 1000 - n % 1000;
*/

/*@
    requires is_valid_n(n);
    ensures \result == compute_result(n);
    assigns \nothing;
*/
int32_t func(int32_t n)
{
    uint32_t n_unsigned;
    uint32_t n_mod;
    int32_t result;
    
    //@ assert is_valid_n(n);
    
    if (n < 0) {
        n_unsigned = (uint32_t)(-n);
    } else {
        n_unsigned = (uint32_t)n;
    }
    
    n_mod = n_unsigned % 1000;
    
    if (n_mod == 0) {
        result = 0;
        //@ assert result == compute_result(n);
        return result;
    } else {
        result = (int32_t)(1000 - n_mod);
        //@ assert result == 1000 - n % 1000;
        //@ assert result == compute_result(n);
        return result;
    }
}
