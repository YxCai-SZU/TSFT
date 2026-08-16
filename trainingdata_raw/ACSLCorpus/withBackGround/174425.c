#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer product(integer t, integer s) = t * s;
    
    lemma product_bound: \forall integer t, s; 
        valid_range(t) && valid_range(s) ==> 
        product(t, s) <= 10000 * 10000;
*/

/*@
    requires valid_range(d);
    requires valid_range(t);
    requires valid_range(s);
    ensures \result == (product(t, s) >= d);
*/
bool func(int d, int t, int s) {
    // Variable declarations at top of scope
    int product;
    bool result;
    
    //@ assert valid_range(t);
    //@ assert valid_range(s);
    
    //@ assert product(t, s) <= 10000 * 10000;
    
    product = t * s;
    
    //@ assert product == product(t, s);
    
    result = (product >= d);
    
    //@ assert result == (product(t, s) >= d);
    
    return result;
}
