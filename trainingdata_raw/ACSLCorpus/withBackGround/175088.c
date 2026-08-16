#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma max_property:
        \forall integer a, b, c, d;
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==>
        (product(a, b) >= product(c, d) ? product(a, b) : product(c, d)) >= product(a, b) &&
        (product(a, b) >= product(c, d) ? product(a, b) : product(c, d)) >= product(c, d);
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
    int max1;
    
    //@ assert a <= 10000 && b <= 10000;
    //@ assert c <= 10000 && d <= 10000;
    
    //@ assert product(a, b) <= 10000 * 10000;
    //@ assert product(c, d) <= 10000 * 10000;
    
    if (a * b > c * d) {
        max1 = a * b;
    } else {
        max1 = c * d;
    }
    
    //@ assert max1 == product(a, b) || max1 == product(c, d);
    //@ assert max1 >= product(a, b);
    //@ assert max1 >= product(c, d);
    
    return max1;
}
