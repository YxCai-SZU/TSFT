#include <stdint.h>

/*@
    predicate non_negative(integer a, integer b, integer c, integer k) =
        a >= 0 && b >= 0 && c >= 0 && k >= 1;

    predicate sum_constraints(integer a, integer b, integer c, integer k) =
        k <= a + b + c && a + b + c <= 2147483647;

    logic integer compute_ans_a(integer a, integer rest) =
        a < rest ? a : rest;

    logic integer compute_ans_b(integer b, integer rest) =
        b < rest ? b : rest;

    logic integer compute_ans_c(integer c, integer rest) =
        c < rest ? c : rest;

    lemma ans_non_negative:
        \forall integer a, b, c, k, ans_a, ans_b, ans_c, rest1, rest2, rest3, ans;
        non_negative(a, b, c, k) && sum_constraints(a, b, c, k) &&
        ans_a == compute_ans_a(a, k) &&
        rest1 == k - ans_a &&
        ans_b == compute_ans_b(b, rest1) &&
        rest2 == rest1 - ans_b &&
        ans_c == compute_ans_c(c, rest2) &&
        rest3 == rest2 - ans_c &&
        ans == ans_a - rest3 ==>
        ans >= 0;

    lemma ans_bound_by_k:
        \forall integer a, b, c, k, ans_a, ans_b, ans_c, rest1, rest2, rest3, ans;
        non_negative(a, b, c, k) && sum_constraints(a, b, c, k) &&
        ans_a == compute_ans_a(a, k) &&
        rest1 == k - ans_a &&
        ans_b == compute_ans_b(b, rest1) &&
        rest2 == rest1 - ans_b &&
        ans_c == compute_ans_c(c, rest2) &&
        rest3 == rest2 - ans_c &&
        ans == ans_a - rest3 ==>
        ans <= k;
*/

/*@
    requires non_negative(A, B, C, K);
    requires sum_constraints(A, B, C, K);
    ensures \result >= 0;
    ensures \result <= K;
*/
int64_t func(int64_t A, int64_t B, int64_t C, int64_t K)
{
    int64_t ans;
    int64_t rest;
    int64_t ans_a;
    int64_t ans_b;
    int64_t ans_c;

    ans = 0;
    rest = K;

    //@ assert rest == K;

    ans_a = (A < rest) ? A : rest;
    //@ assert ans_a == compute_ans_a(A, rest);
    rest = rest - ans_a;
    //@ assert rest == K - ans_a;

    ans_b = (B < rest) ? B : rest;
    //@ assert ans_b == compute_ans_b(B, rest);
    rest = rest - ans_b;
    //@ assert rest == K - ans_a - ans_b;

    ans_c = (C < rest) ? C : rest;
    //@ assert ans_c == compute_ans_c(C, rest);
    rest = rest - ans_c;
    //@ assert rest == K - ans_a - ans_b - ans_c;

    ans = ans_a - rest;
    //@ assert ans == ans_a - rest;

    //@ assert ans >= 0;
    //@ assert ans <= K;

    return ans;
}
