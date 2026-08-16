/*@
    predicate valid_range(integer x) = 1 <= x <= 10;

    logic integer sum_product(integer a, integer b, integer c) = (a + b) * c;

    lemma sum_bounds: \forall integer a, b; valid_range(a) && valid_range(b) ==> 1 <= a + b <= 20;
    lemma product_bounds: \forall integer a, b, c; valid_range(a) && valid_range(b) && valid_range(c) ==> 1 <= sum_product(a, b, c) <= 200;
*/

#include <stdint.h>

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    ensures \result == sum_product(a, b, c);
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c) {
    uint32_t result;

    //@ assert 1 <= a + b <= 20;
    //@ assert 1 <= (a + b) * c <= 200;

    result = (a + b) * c;
    return result;
}
