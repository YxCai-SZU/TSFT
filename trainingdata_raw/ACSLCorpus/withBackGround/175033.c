#include <limits.h>

/*@
    predicate nonneg_params(integer a, integer b, integer c, integer k) =
        a >= 0 && b >= 0 && c >= 0 && k >= 1 &&
        k <= a + b + c && a + b + c <= 2000000000;

    logic integer min_a_k(integer a, integer k) =
        (a < k) ? a : k;

    logic integer k_a(integer k, integer min_a_k) =
        k - min_a_k;

    logic integer min_k_a_b(integer k_a, integer b) =
        (k_a < b) ? k_a : b;

    logic integer max_0_min_k_a_b_minus_k_a(integer min_k_a_b, integer k_a) =
        (0 > min_k_a_b - k_a) ? 0 : min_k_a_b - k_a;

    lemma min_a_k_bounds: \forall integer a, k;
        nonneg_params(a, 0, 0, k) ==> min_a_k(a, k) <= a && min_a_k(a, k) >= 0;

    lemma k_a_bounds: \forall integer k, min_a_k;
        k >= min_a_k && min_a_k >= 0 && k <= 2000000000 ==> 
        k_a(k, min_a_k) >= 0 && k_a(k, min_a_k) <= 2000000000;

    lemma result_bounds: \forall integer a, b, c, k;
        nonneg_params(a, b, c, k) ==>
        min_a_k(a, k) - max_0_min_k_a_b_minus_k_a(min_k_a_b(k_a(k, min_a_k(a, k)), b), k_a(k, min_a_k(a, k))) <= a &&
        min_a_k(a, k) - max_0_min_k_a_b_minus_k_a(min_k_a_b(k_a(k, min_a_k(a, k)), b), k_a(k, min_a_k(a, k))) >= -c;
*/

/*@
    requires nonneg_params(a, b, c, k);
    ensures \result <= a;
    ensures \result >= -c;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int min_a_k;
    int k_a_val;
    int min_k_a_b;
    int max_0_min_k_a_b_minus_k_a;
    int result;

    //@ assert a >= 0 && b >= 0 && c >= 0 && k >= 1;
    //@ assert k <= a + b + c && a + b + c <= 2000000000;

    min_a_k = (a < k) ? a : k;
    //@ assert min_a_k <= a && min_a_k >= 0;

    //@ assert k >= min_a_k && min_a_k >= 0 && k <= 2000000000;
    k_a_val = k - min_a_k;

    min_k_a_b = (k_a_val < b) ? k_a_val : b;

    max_0_min_k_a_b_minus_k_a = (0 > min_k_a_b - k_a_val) ? 0 : min_k_a_b - k_a_val;

    //@ assert min_a_k <= a;
    //@ assert max_0_min_k_a_b_minus_k_a >= -c;
    //@ assert min_a_k - max_0_min_k_a_b_minus_k_a <= a - (-c);

    result = min_a_k - max_0_min_k_a_b_minus_k_a;
    return result;
}
