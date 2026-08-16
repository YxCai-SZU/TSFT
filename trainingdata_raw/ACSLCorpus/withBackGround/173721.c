#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 2 <= n && n <= 100;

    logic integer n_half(integer n) = n / 2;
    logic integer n_plus_1_half(integer n) = (n + 1) / 2;
    logic integer expected_result(integer n) = n_half(n) * n_plus_1_half(n);

    lemma half_bounds:
        \forall integer n; is_valid_n(n) ==> 
            1 <= n_half(n) && n_half(n) <= 50 &&
            1 <= n_plus_1_half(n) && n_plus_1_half(n) <= 50;

    lemma product_bound:
        \forall integer n; is_valid_n(n) ==> 
            n_half(n) * n_plus_1_half(n) <= 2500;
*/

/*@
    requires is_valid_n(n);
    ensures \result == expected_result(n);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t n_half;
    uint64_t n_plus_1_half;
    uint64_t result;

    //@ assert is_valid_n(n);
    
    n_half = n / 2;
    n_plus_1_half = (n + 1) / 2;
    
    //@ assert n_half == n_half(n);
    //@ assert n_plus_1_half == n_plus_1_half(n);
    
    //@ assert 1 <= n_half && n_half <= 50;
    //@ assert 1 <= n_plus_1_half && n_plus_1_half <= 50;
    
    //@ assert n_half * n_plus_1_half <= 2500;
    
    result = n_half * n_plus_1_half;
    
    //@ assert result == expected_result(n);
    return result;
}
