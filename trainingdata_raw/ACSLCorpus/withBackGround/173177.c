#include <stdint.h>

/*@
    predicate bounds_1_10000(integer v) = 1 <= v && v <= 10000;
    logic integer total_cost(integer n, integer k, integer x, integer y) =
        n <= k ? n * x : k * x + (n - k) * y;
    lemma total_cost_bounds:
        \forall integer n, k, x, y;
            bounds_1_10000(n) && bounds_1_10000(k) && bounds_1_10000(x) &&
            bounds_1_10000(y) && y < x ==>
            total_cost(n, k, x, y) == (n <= k ? n * x : k * x + (n - k) * y);
*/

/*@
    requires 1 <= n && n <= 10000;
    requires 1 <= k && k <= 10000;
    requires 1 <= x && x <= 10000;
    requires 1 <= y && y <= 10000;
    requires y < x;
    ensures \result == total_cost(n, k, x, y);
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t k, uint32_t x, uint32_t y) {
    uint32_t res;
    //@ assert bounds_1_10000(n);
    //@ assert bounds_1_10000(k);
    //@ assert bounds_1_10000(x);
    //@ assert bounds_1_10000(y);
    //@ assert y < x;

    if (n <= k) {
        //@ assert total_cost(n, k, x, y) == n * x;
        res = n * x;
    } else {
        //@ assert total_cost(n, k, x, y) == k * x + (n - k) * y;
        res = k * x + (n - k) * y;
    }
    //@ assert res == total_cost(n, k, x, y);
    return res;
}
