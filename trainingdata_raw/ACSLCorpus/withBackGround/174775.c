#include <limits.h>

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
int func(int a, int b, int c, int d)
{
    int sa;
    int sc;
    int res;
    
    //@ assert product(a, b) >= 1;
    //@ assert product(c, d) >= 1;
    
    sa = a * b;
    sc = c * d;
    
    //@ assert sa == product(a, b);
    //@ assert sc == product(c, d);
    
    if (sa > sc) {
        res = sa;
    } else {
        res = sc;
    }
    
    //@ assert res == product(a, b) || res == product(c, d);
    //@ assert res >= 1;
    
    return res;
}
