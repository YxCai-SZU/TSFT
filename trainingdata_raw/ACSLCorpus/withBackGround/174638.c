#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_range:
        \forall integer x, y; valid_range(x) && valid_range(y) ==> 
        1 <= product(x, y) <= 10000 * 10000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= 1;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    // Variable declarations at scope top
    int64_t sa;
    int64_t sc;
    int64_t result;
    
    //@ assert valid_range(a) && valid_range(b);
    //@ assert 1 <= product(a, b) <= 10000 * 10000;
    sa = a * b;
    
    //@ assert valid_range(c) && valid_range(d);
    //@ assert 1 <= product(c, d) <= 10000 * 10000;
    sc = c * d;
    
    // Manual max implementation
    if (sa > sc) {
        result = sa;
    } else {
        result = sc;
    }
    
    //@ assert result == product(a, b) || result == product(c, d);
    return result;
}
