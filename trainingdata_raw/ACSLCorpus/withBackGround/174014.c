#include <stdint.h>

/*@
    predicate valid_params(integer n, integer x, integer y) =
        1 <= n && n <= 100 &&
        1 <= x && x <= 10000 &&
        1 <= y && y <= 10000;

    logic integer product(integer n, integer x) = n * x;
    logic integer sum(integer x, integer y) = x + y;

    lemma product_bound: \forall integer n, x; valid_params(n, x, 1) ==> product(n, x) <= 100 * 10000;
    lemma sum_bound: \forall integer x, y; valid_params(1, x, y) ==> sum(x, y) <= 10000 + 10000;
*/

/*@
    requires valid_params(n, x, y);
    ensures \result == product(n, x) || \result == sum(x, y);
    ensures \result >= product(n, x);
    ensures \result >= sum(x, y);
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t x, uint32_t y)
{
    uint32_t product;
    uint32_t sum;
    uint32_t result;

    //@ assert valid_params(n, x, y);
    
    product = n * x;
    //@ assert product == product(n, x);
    
    sum = x + y;
    //@ assert sum == sum(x, y);
    
    //@ assert 1 <= n && n <= 100 && 1 <= x && x <= 10000;
    //@ assert 1 <= x && x <= 10000 && 1 <= y && y <= 10000;
    
    if (product > sum) {
        result = product;
    } else {
        result = sum;
    }
    
    //@ assert result == product || result == sum;
    //@ assert result >= product;
    //@ assert result >= sum;
    
    return result;
}
