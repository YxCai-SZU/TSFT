#include <stdint.h>
/*@
    predicate is_valid_x(integer x) = 1 <= x && x <= 1000000000000000;

    logic integer compute_ans(integer q, integer r) =
        q * 2 + (r > 6 ? 2 : (r > 0 ? 1 : 0));

    lemma ans_bound: \forall integer x, q, r;
        is_valid_x(x) && 0 <= q <= x / 11 && r == x - 11 * q ==>
        compute_ans(q, r) <= x;
*/

/*@
    requires is_valid_x(x);
    ensures \result <= x;
    assigns \nothing;
*/
uint64_t func(uint64_t x) {
    uint64_t q;
    uint64_t temp_x;
    uint64_t r;
    uint64_t ans;

    q = 0;
    temp_x = x;

    /*@
        loop invariant 1 <= x <= 1000000000000000;
        loop invariant 0 <= q <= x / 11;
        loop invariant temp_x == x - 11 * q;
        loop assigns q, temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 11) {
        temp_x -= 11;
        q += 1;
    }

    r = temp_x;

    //@ assert r == x - 11 * q;

    if (r > 6) {
        ans = q * 2 + 2;
    } else if (r > 0) {
        ans = q * 2 + 1;
    } else {
        ans = q * 2;
    }

    //@ assert ans == compute_ans(q, r);
    //@ assert ans <= x;

    return ans;
}
