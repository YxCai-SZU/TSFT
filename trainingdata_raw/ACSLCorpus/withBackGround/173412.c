#include <stdint.h>

/*@
    predicate is_valid_params(integer n, integer m) =
        1 <= n <= 1000000000000 &&
        1 <= m <= 1000000000000;

    logic integer min_val(integer n, integer m) =
        n < m ? n : m;

    logic integer compute_ans(integer n, integer m) =
        min_val(n, m) + (n - min_val(n, m)) / 4;

    lemma ans_bounds: \forall integer n, m;
        is_valid_params(n, m) ==>
        compute_ans(n, m) <= n + m &&
        compute_ans(n, m) >= 0;
*/

/*@
    requires is_valid_params(n, m);
    ensures \result <= n + m;
    ensures \result >= 0;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t min_val;
    uint64_t ans;

    //@ assert is_valid_params(n, m);

    if (n < m) {
        min_val = n;
    } else {
        min_val = m;
    }

    //@ assert min_val == min_val(n, m);
    //@ assert compute_ans(n, m) == min_val + (n - min_val) / 4;

    ans = min_val + (n - min_val) / 4;

    //@ assert ans == compute_ans(n, m);
    //@ assert ans <= n + m;
    //@ assert ans >= 0;

    return ans;
}
