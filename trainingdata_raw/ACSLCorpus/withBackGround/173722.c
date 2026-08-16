#include <stdint.h>

/*@
    predicate is_valid_range(integer N) = 1 <= N <= 10000;
    
    logic integer compute_result(integer N) = (1000 - N % 1000) % 1000;
    
    lemma result_properties:
        \forall integer N;
        is_valid_range(N) ==> 
            compute_result(N) >= 0 && compute_result(N) < 1000;
*/

/*@
    requires is_valid_range(N);
    ensures \result >= 0;
    ensures \result < 1000;
    ensures \result == compute_result(N);
    assigns \nothing;
*/
int32_t func(int32_t N)
{
    uint32_t N_unsigned;
    uint32_t result;
    
    //@ assert is_valid_range(N);
    
    if (N < 0) {
        N_unsigned = (uint32_t)(-N);
    } else {
        N_unsigned = (uint32_t)N;
    }
    
    result = (1000 - N_unsigned % 1000) % 1000;
    
    //@ assert result == compute_result(N);
    
    return (int32_t)result;
}
