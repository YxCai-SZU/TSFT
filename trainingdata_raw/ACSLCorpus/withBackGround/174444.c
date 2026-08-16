#include <stdint.h>

/*@
    predicate valid_n(integer n) = 2 <= n && n <= 100;
    
    logic integer half(integer n) = n / 2;
    logic integer remainder(integer n) = n - half(n);
    logic integer product(integer n) = half(n) * remainder(n);
    
    lemma half_bounds: \forall integer n; valid_n(n) ==> 1 <= half(n) <= 50;
    lemma remainder_bounds: \forall integer n; valid_n(n) ==> 1 <= remainder(n) <= 50;
    lemma product_bounds: \forall integer n; valid_n(n) ==> product(n) <= 2500;
*/

/*@
    requires valid_n(n);
    ensures \result == product(n);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t half_n;
    uint32_t remainder;
    uint32_t product;
    int32_t result;
    
    //@ assert 2 <= n && n <= 100;
    
    //@ assert n / 2 >= 1 && n / 2 <= 50;
    half_n = n / 2;
    
    //@ assert n - half_n >= 1 && n - half_n <= 50;
    remainder = n - half_n;
    
    //@ assert half_n * remainder <= 2500;
    product = half_n * remainder;
    
    result = (int32_t)product;
    //@ assert result == (n / 2) * (n - n / 2);
    
    return result;
}
