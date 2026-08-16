#include <stdint.h>

/*@
    predicate valid_params(integer n, integer a, integer b) =
        1 <= n && n <= 20 && 1 <= a && a <= 50 && 1 <= b && b <= 50;

    logic integer safe_product(integer n, integer a) = n * a;

    lemma product_bounds:
        \forall integer n, integer a;
        valid_params(n, a, 50) ==> 1 <= safe_product(n, a) && safe_product(n, a) <= 1000;
*/

/*@
    requires valid_params(n, a, b);
    ensures \result >= 0 && \result <= (int32_t)b;
*/
int32_t func(uint32_t n, uint32_t a, uint32_t b)
{
    // Declare all variables at scope top
    uint32_t product;
    int32_t result;

    //@ assert valid_params(n, a, b);
    product = n * a;

    //@ assert 1 <= product && product <= 1000;
    if (product < b) {
        //@ assert product >= 0 && product <= b;
        result = (int32_t)product;
    } else {
        result = (int32_t)b;
    }

    //@ assert result >= 0 && result <= (int32_t)b;
    return result;
}
