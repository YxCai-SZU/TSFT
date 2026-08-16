#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k) =
        2 <= k <= n <= 100000;

    logic integer result_lower_bound(integer n, integer k) =
        (n - 1) / (k - 1);

    logic integer result_upper_bound(integer n, integer k) =
        (n - 1) / (k - 1) + 1;

    lemma arithmetic_bounds:
        \forall integer n, k; valid_params(n, k) ==>
            n - 1 >= 0 && k - 1 >= 1 && (n - 1) / (k - 1) <= 100000;
*/

/*@
    requires valid_params(n, k);
    ensures \result >= result_lower_bound(n, k);
    ensures \result <= result_upper_bound(n, k);
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t k) {
    // Variable declarations at scope top
    uint64_t ans;
    uint64_t ost;
    uint64_t result;

    //@ assert n - 1 >= 0;
    //@ assert k - 1 >= 1;
    //@ assert (n - 1) / (k - 1) <= 100000;

    ans = (n - 1) / (k - 1);
    ost = (n - 1) % (k - 1);

    if (ost == 0) {
        result = ans;
    } else {
        result = ans + 1;
    }

    //@ assert result >= (n - 1) / (k - 1);
    //@ assert result <= (n - 1) / (k - 1) + 1;
    return result;
}
