#include <stdint.h>

/*@
    predicate valid_range(integer k) = 1 <= k <= 200;

    logic integer half(integer k) = k / 2;
    logic integer complement(integer k) = k - half(k);
    logic integer expected_result(integer k) = half(k) * complement(k);

    lemma half_bounds: \forall integer k; valid_range(k) ==> 0 <= half(k) <= 100;
    lemma complement_bounds: \forall integer k; valid_range(k) ==> 0 <= complement(k) <= 100;
    lemma product_bounds: \forall integer k; valid_range(k) ==> half(k) * complement(k) <= 10000;
    lemma product_identity: \forall integer k; valid_range(k) ==> 
        half(k) * complement(k) == (k / 2) * (k - k / 2);
*/

/*@
    requires 1 <= k <= 200;
    ensures \result == (k / 2) * (k - k / 2);
    assigns \nothing;
*/
int32_t func(uint32_t k) {
    uint32_t t;
    uint32_t b;
    int32_t ans;

    t = k / 2;
    b = k - t;

    //@ assert 0 <= t <= 100;
    //@ assert 0 <= b <= 100;
    //@ assert t * b <= 10000;
    //@ assert t * b == (k / 2) * (k - k / 2);

    ans = (int32_t)(t * b);
    return ans;
}
