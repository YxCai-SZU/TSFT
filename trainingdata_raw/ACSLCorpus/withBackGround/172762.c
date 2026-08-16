#include <stdint.h>

/*@ predicate is_safe_mult(uint32_t n) = n <= 46340; */

/*@ lemma square_bound: 
      \forall uint32_t n; is_safe_mult(n) ==> (uint64_t)n * (uint64_t)n <= 2147395600; */

/*@ requires is_safe_mult(n);
    ensures \result == n * n;
    ensures \result == (uint32_t)((uint64_t)n * (uint64_t)n);
    assigns \nothing;
*/
uint32_t square_number(uint32_t n) {
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert is_safe_mult(n);
    
    //@ assert (uint64_t)n * (uint64_t)n <= 2147395600;
    
    result = n * n;
    
    //@ assert result == n * n;
    //@ assert result == (uint32_t)((uint64_t)n * (uint64_t)n);
    
    return result;
}
