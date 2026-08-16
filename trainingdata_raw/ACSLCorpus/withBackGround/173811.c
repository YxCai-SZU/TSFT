#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x && x <= 10000;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_bound: \forall integer a, b; 
        valid_range(a) && valid_range(b) ==> product(a, b) <= 100000000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= product(a, b);
    ensures \result >= product(c, d);
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d)
{
    // Variable declarations at top of scope
    uint64_t sa;
    uint64_t sc;
    uint64_t ans;
    
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert product(a, b) <= 100000000;
    
    sa = a * b;
    
    //@ assert valid_range(c);
    //@ assert valid_range(d);
    //@ assert product(c, d) <= 100000000;
    
    sc = c * d;
    
    if (sa > sc) {
        ans = sa;
    } else {
        ans = sc;
    }
    
    //@ assert ans == product(a, b) || ans == product(c, d);
    //@ assert ans >= product(a, b);
    //@ assert ans >= product(c, d);
    
    return ans;
}
