#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_bounds:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> 
            product(x, y) >= 1 && product(x, y) <= 100000000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= 1;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t sa;
    int64_t sc;
    int64_t max_value;
    
    //@ assert product(a, b) >= 1 && product(a, b) <= 100000000;
    sa = a * b;
    
    //@ assert product(c, d) >= 1 && product(c, d) <= 100000000;
    sc = c * d;
    
    if (sa > sc) {
        max_value = sa;
        //@ assert max_value == product(a, b);
        //@ assert max_value >= 1;
    } else {
        max_value = sc;
        //@ assert max_value == product(c, d);
        //@ assert max_value >= 1;
    }
    
    return max_value;
}
