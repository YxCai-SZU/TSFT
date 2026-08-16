#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer multiply_sum(integer a, integer b, integer c) = (a + b) * c;

    lemma sum_bounds:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> 2 <= a + b <= 200;

    lemma product_bounds:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==> 
            (a + b) * c <= 20000;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    ensures \result == multiply_sum(a, b, c);
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c)
{
    int32_t ab;
    int32_t result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    
    ab = a + b;
    
    //@ assert 2 <= ab <= 200;
    //@ assert ab * c <= 20000;
    
    result = ab * c;
    
    //@ assert result == multiply_sum(a, b, c);
    return result;
}
