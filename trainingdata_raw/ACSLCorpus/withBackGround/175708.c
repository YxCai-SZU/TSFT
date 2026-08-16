#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_bounded:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> product(a, b) <= INT_MAX;
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
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);
    
    //@ assert product(a, b) <= INT_MAX;
    //@ assert product(c, d) <= INT_MAX;
    
    int ab_product;
    int cd_product;
    int res;
    
    ab_product = a * b;
    cd_product = c * d;
    
    if (ab_product > cd_product) {
        res = ab_product;
    } else {
        res = cd_product;
    }
    
    //@ assert res == product(a, b) || res == product(c, d);
    //@ assert res >= product(a, b);
    //@ assert res >= product(c, d);
    
    return res;
}
