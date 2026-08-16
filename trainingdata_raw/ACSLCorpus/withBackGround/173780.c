#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer h) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= h && h <= 100 &&
        h % 2 == 0;

    logic integer expected_result(integer a, integer b, integer h) =
        (a + b) * h / 2;

    lemma sum_bound: \forall integer a, b;
        valid_params(a, b, 1) ==> a + b <= 200;

    lemma product_bound: \forall integer a, b, h;
        valid_params(a, b, h) ==> (a + b) * h <= 20000;
*/

/*@
    requires valid_params(a, b, h);
    ensures \result == expected_result(a, b, h);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t h) {
    uint32_t sum;
    uint32_t product;
    uint32_t ans;

    sum = a + b;
    //@ assert sum <= 200;
    
    product = sum * h;
    //@ assert product <= 20000;
    
    ans = product / 2;
    //@ assert ans == expected_result(a, b, h);
    
    return ans;
}
