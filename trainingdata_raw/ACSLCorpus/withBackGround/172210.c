#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 2 <= n && n <= 100;
    
    logic integer half(integer n) = n / 2;
    logic integer half_plus_one(integer n) = (n + 1) / 2;
    logic integer expected_result(integer n) = half(n) * half_plus_one(n);
    
    lemma result_bounds:
        \forall integer n; is_valid_n(n) ==> 
            half(n) <= 50 && half_plus_one(n) <= 50;
    
    lemma product_bounds:
        \forall integer n; is_valid_n(n) ==> 
            expected_result(n) <= 2500;
*/

/*@
    requires is_valid_n(n);
    ensures \result == expected_result(n);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at scope top
    uint64_t result;
    
    // Precondition verification
    //@ assert n >= 2 && n <= 100;
    
    // Result bounds verification
    //@ assert n / 2 <= 50;
    //@ assert (n + 1) / 2 <= 50;
    //@ assert (n / 2) * ((n + 1) / 2) <= 2500;
    
    result = (n / 2) * ((n + 1) / 2);
    
    // Postcondition verification
    //@ assert result == expected_result(n);
    
    return result;
}
