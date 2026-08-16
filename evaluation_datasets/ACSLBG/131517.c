#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_range:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> 
            1 <= product(x, y) <= 100000000;
*/


int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);
    
    //@ assert 1 <= product(a, b) <= 100000000;
    //@ assert 1 <= product(c, d) <= 100000000;
    
    int64_t product_ab;
    int64_t product_cd;
    int64_t max_value;
    
    product_ab = a * b;
    product_cd = c * d;
    
    //@ assert product_ab == product(a, b);
    //@ assert product_cd == product(c, d);
    
    if (product_ab > product_cd) {
        max_value = product_ab;
        //@ assert max_value == product(a, b);
    } else {
        max_value = product_cd;
        //@ assert max_value == product(c, d);
    }
    
    //@ assert max_value >= 1;
    return max_value;
}
