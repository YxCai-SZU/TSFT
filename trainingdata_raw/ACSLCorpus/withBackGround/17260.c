#include <limits.h>

/*@
    predicate valid_input(integer a, integer b, integer c, integer k) =
        0 <= a && 0 <= b && 0 <= c &&
        1 <= k && k <= a + b + c &&
        a + b + c <= 2000000000;

    logic integer min_a_k(integer a, integer k) = (a < k) ? a : k;

    logic integer min_k_a_b(integer a, integer b, integer c, integer k) =
        (k - a - b < c) ? k - a - b : c;

    logic integer max_min_k_a_b_0(integer a, integer b, integer c, integer k) =
        (min_k_a_b(a, b, c, k) > 0) ? min_k_a_b(a, b, c, k) : 0;

    logic integer compute_ans(integer a, integer b, integer c, integer k) =
        min_a_k(a, k) - max_min_k_a_b_0(a, b, c, k);

    lemma ans_bounds:
        \forall integer a, b, c, k;
        valid_input(a, b, c, k) ==>
        compute_ans(a, b, c, k) <= a &&
        compute_ans(a, b, c, k) >= -c;
*/

/*@
    requires valid_input(a, b, c, k);
    ensures \result <= a && \result >= -c;
*/
int func(int a, int b, int c, int k)
{
    int min_a_k;
    int min_k_a_b;
    int max_min_k_a_b_0;
    int ans;

    //@ assert valid_input(a, b, c, k);
    
    if (a < k) {
        min_a_k = a;
    } else {
        min_a_k = k;
    }
    //@ assert min_a_k == min_a_k(a, k);
    
    if (k - a - b < c) {
        min_k_a_b = k - a - b;
    } else {
        min_k_a_b = c;
    }
    //@ assert min_k_a_b == min_k_a_b(a, b, c, k);
    
    if (min_k_a_b > 0) {
        max_min_k_a_b_0 = min_k_a_b;
    } else {
        max_min_k_a_b_0 = 0;
    }
    //@ assert max_min_k_a_b_0 == max_min_k_a_b_0(a, b, c, k);
    
    ans = min_a_k - max_min_k_a_b_0;
    //@ assert ans == compute_ans(a, b, c, k);
    
    return ans;
}
