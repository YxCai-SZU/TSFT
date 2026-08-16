#include <stdint.h>

/*@ predicate is_valid_n(integer n) = 1 <= n && n <= 100; */

/*@ logic integer sum_formula(integer n) = n * (n + 1) / 2; */

/*@ lemma sum_formula_bounds: 
      \forall integer n; is_valid_n(n) ==> sum_formula(n) <= 5050; */

/*@ requires is_valid_n(n);
    ensures \result == sum_formula(n);
    assigns \nothing;
 */
uint32_t func(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert n >= 1 && n <= 100;
    //@ assert n * (n + 1) / 2 <= 5050;
    
    result = n * (n + 1) / 2;
    
    //@ assert result == sum_formula(n);
    return result;
}
