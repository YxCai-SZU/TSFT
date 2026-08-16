#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        0 <= a && 0 <= b && 0 <= c &&
        1 <= k && k <= a + b + c && k <= 2000000000;

    logic integer compute_sum(integer a, integer b, integer c, integer k) =
        (a >= k) ? k : 
        (a + b >= k) ? a : 
        a - (k - a - b);
*/

/*@
    lemma sum_bounds: \forall integer a, b, c, k;
        valid_params(a, b, c, k) ==> 
        compute_sum(a, b, c, k) >= -c && compute_sum(a, b, c, k) <= a;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result >= -c && \result <= a;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k) {
    int32_t sum = 0;
    int32_t remaining = k;

    //@ assert valid_params(a, b, c, k);
    
    if (a >= remaining) {
        sum += remaining;
        remaining = 0;
    } else {
        sum += a;
        remaining -= a;
    }

    //@ assert sum >= 0 && sum <= a;
    
    if (b >= remaining) {
        remaining = 0;
    } else {
        remaining -= b;
    }

    //@ assert remaining >= 0 && remaining <= c;

    sum -= remaining;

    //@ assert sum >= -c && sum <= a;

    return sum;
}
