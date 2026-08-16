#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_bounds:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> 
        1 <= product(a, b) <= 10000 * 10000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= product(a, b);
    ensures \result >= product(c, d);
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long sa;
    long sc;
    long ans;
    
    //@ assert valid_range(a) && valid_range(b);
    //@ assert 1 <= product(a, b) <= 10000 * 10000;
    
    //@ assert valid_range(c) && valid_range(d);
    //@ assert 1 <= product(c, d) <= 10000 * 10000;
    
    sa = a * b;
    sc = c * d;
    
    //@ assert sa == product(a, b);
    //@ assert sc == product(c, d);
    
    if (sa > sc) {
        ans = sa;
        //@ assert ans == product(a, b);
    } else {
        ans = sc;
        //@ assert ans == product(c, d);
    }
    
    //@ assert ans >= product(a, b);
    //@ assert ans >= product(c, d);
    
    return ans;
}
