#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        0 <= a && 0 <= b && 0 <= c &&
        1 <= k && k <= a + b + c &&
        a + b + c <= 2000000000;

    logic integer compute_a_cnt(integer a, integer k) =
        a < k ? a : k;

    logic integer compute_k_cnt(integer k, integer a_cnt) =
        k - a_cnt;

    logic integer compute_b_cnt(integer b, integer k_cnt) =
        b > k_cnt ? k_cnt : b;

    logic integer compute_c_cnt(integer k_cnt) =
        -k_cnt;

    logic integer compute_ans(integer a_cnt, integer c_cnt) =
        a_cnt + c_cnt;

    lemma ans_bound:
        \forall integer a, b, c, k, a_cnt, k_cnt, b_cnt, c_cnt, ans;
        valid_params(a, b, c, k) &&
        a_cnt == compute_a_cnt(a, k) &&
        k_cnt == compute_k_cnt(k, a_cnt) &&
        b_cnt == compute_b_cnt(b, k_cnt) &&
        c_cnt == compute_c_cnt(k_cnt - b_cnt) &&
        ans == compute_ans(a_cnt, c_cnt) ==>
        ans <= a + b + c;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result <= a + b + c;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t ans;
    int32_t a_cnt;
    int32_t k_cnt;
    int32_t b_cnt;
    int32_t c_cnt;

    a_cnt = a < k ? a : k;
    k_cnt = k - a_cnt;
    b_cnt = b > k_cnt ? k_cnt : b;
    k_cnt = k_cnt - b_cnt;
    c_cnt = -k_cnt;
    ans = a_cnt + c_cnt;

    //@ assert ans <= a + b + c;

    return ans;
}
