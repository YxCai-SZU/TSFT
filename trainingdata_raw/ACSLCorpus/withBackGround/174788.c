#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer max_product(integer t, integer s) = t * s;
    
    lemma product_bound: 
        \forall integer t, s; 
        valid_range(t) && valid_range(s) ==> 
        max_product(t, s) <= 10000 * 10000;
*/

/*@
    requires valid_range(d);
    requires valid_range(t);
    requires valid_range(s);
    ensures \result == (d <= t * s);
*/
bool func(long d, long t, long s)
{
    // Variable declarations at top of scope
    bool result;
    
    // Precondition assertions
    //@ assert valid_range(d);
    //@ assert valid_range(t);
    //@ assert valid_range(s);
    
    // Product bound verification
    //@ assert max_product(t, s) <= 10000 * 10000;
    
    result = (d <= t * s);
    
    // Postcondition verification
    //@ assert result == (d <= t * s);
    
    return result;
}
