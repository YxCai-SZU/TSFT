#include <limits.h>

/*@
    predicate valid_input(integer a, integer b, integer c, integer k) =
        0 <= a <= 100 &&
        0 <= b <= 100 &&
        0 <= c <= 100 &&
        1 <= k <= 3;

    logic integer compute_a_cnt(integer a, integer k) =
        a < k ? a : k;

    logic integer compute_b_cnt(integer a, integer b, integer k) =
        b < k - compute_a_cnt(a, k) ? b : k - compute_a_cnt(a, k);

    logic integer compute_c_cnt(integer a, integer b, integer c, integer k) =
        c < k - compute_a_cnt(a, k) - compute_b_cnt(a, b, k) ?
        c : k - compute_a_cnt(a, k) - compute_b_cnt(a, b, k);

    logic integer compute_ans(integer a, integer b, integer c, integer k) =
        compute_a_cnt(a, k) - compute_c_cnt(a, b, c, k);

    logic integer compute_max_val(integer a, integer b, integer c, integer k) =
        compute_ans(a, b, c, k) > 0 ? compute_ans(a, b, c, k) : 0;

    lemma ans_bounds:
        \forall integer a, b, c, k;
        valid_input(a, b, c, k) ==>
        compute_ans(a, b, c, k) >= -(a + b + c) &&
        compute_ans(a, b, c, k) <= a + b + c;

    lemma max_val_bounds:
        \forall integer a, b, c, k;
        valid_input(a, b, c, k) ==>
        compute_max_val(a, b, c, k) >= 0 &&
        compute_max_val(a, b, c, k) <= a + b + c + 1;
*/

/*@
    requires valid_input(a, b, c, k);
    ensures \result >= 0;
    ensures \result <= a + b + c + 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int a_cnt;
    int b_cnt;
    int c_cnt;
    int ans;
    int max_val;

    //@ assert valid_input(a, b, c, k);

    if (a < k)
    {
        a_cnt = a;
    }
    else
    {
        a_cnt = k;
    }
    //@ assert a_cnt == compute_a_cnt(a, k);

    if (b < k - a_cnt)
    {
        b_cnt = b;
    }
    else
    {
        b_cnt = k - a_cnt;
    }
    //@ assert b_cnt == compute_b_cnt(a, b, k);

    if (c < k - a_cnt - b_cnt)
    {
        c_cnt = c;
    }
    else
    {
        c_cnt = k - a_cnt - b_cnt;
    }
    //@ assert c_cnt == compute_c_cnt(a, b, c, k);

    ans = a_cnt - c_cnt;
    //@ assert ans == compute_ans(a, b, c, k);

    max_val = ans;
    if (0 > ans)
    {
        max_val = 0;
    }
    //@ assert max_val == compute_max_val(a, b, c, k);

    //@ assert max_val >= 0;
    //@ assert max_val <= a + b + c + 1;

    return max_val;
}
