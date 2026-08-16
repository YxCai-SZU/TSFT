#include <stdint.h>

/*@
    predicate non_negative(integer a, integer b, integer c, integer k) =
        a >= 0 && b >= 0 && c >= 0 && k >= 1;

    predicate k_bounds(integer a, integer b, integer c, integer k) =
        k <= a + b + c && k <= 2000000000;

    logic integer compute_ans(integer a_cnt, integer c_cnt) =
        a_cnt - c_cnt;

    lemma ans_upper_bound:
        \forall integer a, a_cnt, c_cnt;
        a_cnt <= a && c_cnt >= 0 ==> compute_ans(a_cnt, c_cnt) <= a;

    lemma ans_lower_bound:
        \forall integer c, a_cnt, c_cnt;
        a_cnt >= 0 && c_cnt <= c ==> compute_ans(a_cnt, c_cnt) >= -c;
*/

/*@
    requires non_negative(a, b, c, k);
    requires k_bounds(a, b, c, k);
    ensures \result <= a;
    ensures \result >= -c;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t k_remaining;
    int64_t a_cnt;
    int64_t b_cnt;
    int64_t c_cnt;
    int64_t ans;

    k_remaining = k;

    //@ assert k_remaining >= 0 && k_remaining <= k;
    a_cnt = (k_remaining < a) ? k_remaining : a;
    k_remaining = k_remaining - a_cnt;

    //@ assert k_remaining >= 0 && k_remaining <= k;
    b_cnt = (k_remaining < b) ? k_remaining : b;
    k_remaining = k_remaining - b_cnt;

    //@ assert k_remaining >= 0 && k_remaining <= k;
    c_cnt = (k_remaining < c) ? k_remaining : c;
    k_remaining = k_remaining - c_cnt;

    ans = a_cnt - c_cnt;

    //@ assert a_cnt <= a;
    //@ assert c_cnt >= 0;
    //@ assert ans <= a;

    //@ assert a_cnt >= 0;
    //@ assert c_cnt <= c;
    //@ assert ans >= -c;

    return ans;
}
