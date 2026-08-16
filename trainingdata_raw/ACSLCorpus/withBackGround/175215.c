#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer h) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= h && h <= 100 &&
        h % 2 == 0;

    logic integer trapezoid_area(integer a, integer b, integer h) =
        (a + b) * h / 2;

    lemma product_bound: \forall integer a, b, h;
        valid_params(a, b, h) ==> (a + b) * h <= 20000;
*/

/*@
    requires valid_params(a, b, h);
    ensures \result == trapezoid_area(a, b, h);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t h)
{
    uint32_t sum;
    uint32_t product;
    uint32_t half_product;

    //@ assert valid_params(a, b, h);
    
    sum = a + b;
    
    //@ assert sum == a + b;
    //@ assert sum * h <= 20000;
    
    product = sum * h;
    half_product = product / 2;
    
    //@ assert half_product == trapezoid_area(a, b, h);
    
    return half_product;
}
