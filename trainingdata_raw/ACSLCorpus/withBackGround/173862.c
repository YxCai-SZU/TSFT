#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 1000000000000000;

    logic integer q_value(integer x) = x / 11;
    logic integer r_value(integer x) = x % 11;

    logic integer lower_bound(integer x) = q_value(x) * 2;
    logic integer upper_bound(integer x) = q_value(x) * 2 + 2;

    lemma remainder_range: \forall integer x; valid_range(x) ==> 0 <= r_value(x) <= 10;
    lemma ans_lower_bound: \forall integer x, integer ans; valid_range(x) && ans >= lower_bound(x) ==> ans >= lower_bound(x);
    lemma ans_upper_bound: \forall integer x, integer ans; valid_range(x) && ans <= upper_bound(x) ==> ans <= upper_bound(x);
*/

/*@
    requires valid_range(x);
    ensures \result >= lower_bound(x);
    ensures \result <= upper_bound(x);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t q;
    uint64_t r;
    uint64_t ans;

    q = x / 11;
    r = x % 11;
    ans = q * 2;

    //@ assert q == q_value(x);
    //@ assert r == r_value(x);
    //@ assert 0 <= r <= 10;

    if (r == 1 || r == 2 || r == 4 || r == 5 || r == 7 || r == 8) {
        ans += 1;
    } else if (r == 3 || r == 6 || r == 9 || r == 10) {
        ans += 2;
    }

    //@ assert ans >= lower_bound(x);
    //@ assert ans <= upper_bound(x);

    return ans;
}
