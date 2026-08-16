#include <stdbool.h>

/*@
    predicate k_in_range(integer k) = 1 <= k && k <= 100;
    predicate x_in_range(integer x) = 1 <= x && x <= 100000;
    
    logic integer safe_product(integer k) = 500 * k;
    
    lemma product_bound: \forall integer k; k_in_range(k) ==> safe_product(k) <= 50000;
*/

/*@
    requires k_in_range(k);
    requires x_in_range(x);
    ensures \result == (safe_product(k) >= x);
    assigns \nothing;
*/
bool func(long k, long x)
{
    bool result;
    
    //@ assert 1 <= k && k <= 100;
    //@ assert 1 <= x && x <= 100000;
    
    //@ assert safe_product(k) <= 50000;
    
    result = (500 * k >= x);
    
    //@ assert result == (safe_product(k) >= x);
    
    return result;
}
