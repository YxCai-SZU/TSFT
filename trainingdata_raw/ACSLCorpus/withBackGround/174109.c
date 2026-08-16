#include <stdint.h>

/*@
    predicate non_negative(integer a, integer b, integer c) =
        a >= 0 && b >= 0 && c >= 0;

    predicate valid_k(integer a, integer b, integer c, integer k) =
        1 <= k && k <= a + b + c;

    logic integer compute_a_cnt(integer a, integer k) =
        a < k ? a : k;

    logic integer compute_b_cnt(integer b, integer k_cnt) =
        b < k_cnt ? b : k_cnt;

    logic integer compute_c_cnt(integer c, integer k_cnt) =
        c < k_cnt ? c : k_cnt;

    lemma final_bound:
        \forall integer a, b, c, k, a_cnt, b_cnt, c_cnt, res, k_cnt;
        non_negative(a, b, c) && valid_k(a, b, c, k) &&
        a_cnt == compute_a_cnt(a, k) &&
        k_cnt == k - a_cnt &&
        b_cnt == compute_b_cnt(b, k_cnt) &&
        k_cnt == k - a_cnt - b_cnt &&
        c_cnt == compute_c_cnt(c, k_cnt) &&
        res == a_cnt - c_cnt ==>
        res <= k;
*/

/*@
    requires non_negative(a, b, c) && valid_k(a, b, c, k);
    ensures \result <= k;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t a_cnt;
    int64_t res;
    int64_t k_cnt;
    int64_t b_cnt;
    int64_t c_cnt;

    //@ assert a >= 0 && b >= 0 && c >= 0;
    //@ assert 1 <= k && k <= a + b + c;

    a_cnt = a < k ? a : k;
    //@ assert a_cnt == compute_a_cnt(a, k);

    res = a_cnt;
    k_cnt = k - a_cnt;

    b_cnt = b < k_cnt ? b : k_cnt;
    //@ assert b_cnt == compute_b_cnt(b, k_cnt);

    k_cnt = k_cnt - b_cnt;

    c_cnt = c < k_cnt ? c : k_cnt;
    //@ assert c_cnt == compute_c_cnt(c, k_cnt);

    res = res - c_cnt;

    //@ assert res <= k;

    return res;
}
