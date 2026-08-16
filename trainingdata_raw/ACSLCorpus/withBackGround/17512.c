#include <limits.h>

/*@
    predicate valid_input(integer a, integer b, integer c, integer k) =
        0 <= a <= 100 &&
        0 <= b <= 100 &&
        0 <= c <= 100 &&
        1 <= k <= a + b + c;

    logic integer min(integer x, integer y) = (x < y) ? x : y;

    lemma ans_lower_bound:
        \forall integer a, b, c, k, min_a, min_c;
        valid_input(a, b, c, k) ==>
        min_a == min(a, k) ==>
        min_c == min(c, k - min_a - min(b, k - min_a)) ==>
        min_a - min_c >= -1 * c;

    lemma ans_upper_bound:
        \forall integer a, b, c, k, min_a, min_c;
        valid_input(a, b, c, k) ==>
        min_a == min(a, k) ==>
        min_c == min(c, k - min_a - min(b, k - min_a)) ==>
        min_a - min_c <= 1 * a;
*/

/*@
    requires valid_input(a, b, c, k);
    ensures \result >= -1 * c;
    ensures \result <= 1 * a;
*/
int func(int a, int b, int c, int k)
{
    int k_remaining;
    int min_a;
    int min_b;
    int min_c;
    int ans;

    k_remaining = k;

    //@ assert 0 <= k_remaining <= a + b + c;

    if (a < k_remaining)
        min_a = a;
    else
        min_a = k_remaining;

    //@ assert min_a == min(a, k);
    //@ assert 0 <= min_a <= a;

    k_remaining = k_remaining - min_a;

    //@ assert 0 <= k_remaining <= b + c;

    if (b < k_remaining)
        min_b = b;
    else
        min_b = k_remaining;

    //@ assert min_b == min(b, k - min_a);
    //@ assert 0 <= min_b <= b;

    k_remaining = k_remaining - min_b;

    //@ assert 0 <= k_remaining <= c;

    if (c < k_remaining)
        min_c = c;
    else
        min_c = k_remaining;

    //@ assert min_c == min(c, k - min_a - min_b);
    //@ assert 0 <= min_c <= c;

    ans = min_a - min_c;

    //@ assert ans >= -1 * c;
    //@ assert ans <= 1 * a;

    return ans;
}
