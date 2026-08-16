#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer safe_product(integer t, integer s) = t * s;
    
    lemma product_bound: 
        \forall integer t, s; 
        valid_range(t) && valid_range(s) ==> 
        safe_product(t, s) <= 10000 * 10000;
*/

/*@
    requires valid_range(d);
    requires valid_range(t);
    requires valid_range(s);
    ensures \result == (d <= t * s);
*/
bool func(int d, int t, int s)
{
    // Variable declarations at scope top
    int product;
    bool result;
    
    //@ assert valid_range(t);
    //@ assert valid_range(s);
    //@ assert safe_product(t, s) <= 10000 * 10000;
    
    product = t * s;
    result = d <= product;
    
    return result;
}
