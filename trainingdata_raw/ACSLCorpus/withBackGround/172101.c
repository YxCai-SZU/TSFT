#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_bound:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> 
            product(x, y) <= 100000000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= product(a, b);
    ensures \result >= product(c, d);
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at scope top
    int product1;
    int product2;
    int max_value;
    
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert product(a, b) <= 100000000;
    
    product1 = a * b;
    
    //@ assert valid_range(c);
    //@ assert valid_range(d);
    //@ assert product(c, d) <= 100000000;
    
    product2 = c * d;
    
    if (product1 > product2) {
        max_value = product1;
        //@ assert max_value == product(a, b);
    } else {
        max_value = product2;
        //@ assert max_value == product(c, d);
    }
    
    //@ assert max_value >= product(a, b);
    //@ assert max_value >= product(c, d);
    
    return max_value;
}
