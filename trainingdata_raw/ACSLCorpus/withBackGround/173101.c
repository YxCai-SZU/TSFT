#include <limits.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_bound: \forall integer a, b; 
        valid_range(a) && valid_range(b) ==> 
        product(a, b) <= 100000000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= product(a, b) && \result >= product(c, d);
    assigns \nothing;
*/
int func(int a, int b, int c, int d) {
    int x;
    int y;
    int result;
    
    //@ assert product(a, b) <= 100000000;
    //@ assert product(c, d) <= 100000000;
    
    x = a * b;
    y = c * d;
    
    if (x < y) {
        result = y;
    } else {
        result = x;
    }
    
    //@ assert result == x || result == y;
    return result;
}
