#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_even(integer x) = x % 2 == 0; */

/*@
    requires 1 <= n <= 100;
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint32_t n) {
    int32_t result;
    
    //@ assert 1 <= n <= 100;
    
    if (n % 2 == 0) {
        result = 1;
    } else {
        uint32_t n_fixed = n / 2 + 1;
        
        //@ assert n_fixed >= 1;
        //@ assert n_fixed <= 51;
        
        if (n_fixed % 2 == 0) {
            result = 0;
        } else {
            //@ assert n_fixed % 2 == 1;
            result = 1;
        }
    }
    
    //@ assert result == 0 || result == 1;
    return result;
}
