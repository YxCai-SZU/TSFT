#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma max_product_property:
        \forall integer a, b, c, d;
            valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==>
            (product(a,b) >= product(c,d) || product(c,d) >= product(a,b));
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == a*b || \result == c*d;
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int sa = a;
    int sb = b;
    int sc = c;
    int sd = d;
    int max_val;
    
    //@ assert valid_range(sa) && valid_range(sb);
    //@ assert sa*sb <= 10000*10000;
    
    //@ assert valid_range(sc) && valid_range(sd);
    //@ assert sc*sd <= 10000*10000;
    
    //@ assert sc*sd >= 1;
    
    max_val = sa * sb;
    
    if (sc * sd > max_val) {
        max_val = sc * sd;
    }
    
    //@ assert max_val == a*b || max_val == c*d;
    
    return max_val;
}
