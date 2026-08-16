#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        1 <= a && a <= 1000000000 &&
        1 <= b && b <= 1000000000 &&
        1 <= c && c <= 1000000000 &&
        1 <= k && k <= a + b + c &&
        a + b >= k;

    logic integer min_val(integer a, integer k) = (a < k) ? a : k;
    logic integer max_val(integer a, integer b, integer k) = 
        (k - (a + b) > 0) ? k - (a + b) : 0;
    logic integer answer(integer a, integer b, integer k) = 
        min_val(a, k) - max_val(a, b, k);

    lemma min_val_nonnegative: \forall integer a, k; a >= 0 && k >= 0 ==> min_val(a, k) >= 0;
    lemma max_val_nonnegative: \forall integer a, b, k; a >= 0 && b >= 0 && k >= 0 ==> max_val(a, b, k) >= 0;
    lemma answer_nonnegative: \forall integer a, b, k; a >= 0 && b >= 0 && k >= 0 && min_val(a, k) >= max_val(a, b, k) ==> answer(a, b, k) >= 0;
    lemma min_val_bound_k: \forall integer a, k; min_val(a, k) <= k;
    lemma max_val_bound_k: \forall integer a, b, k; a >= 0 && b >= 0 && k >= 0 ==> max_val(a, b, k) <= k;
    lemma answer_bound_k: \forall integer a, b, k; answer(a, b, k) <= k;
    lemma min_val_bound_a: \forall integer a, k; min_val(a, k) <= a;
    lemma answer_bound_a: \forall integer a, b, k; answer(a, b, k) <= a;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result >= 0;
    ensures \result <= k;
    ensures \result <= a;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t min_val;
    int64_t max_val;
    int64_t ans;

    //@ assert a >= 1 && a <= 1000000000;
    //@ assert b >= 1 && b <= 1000000000;
    //@ assert c >= 1 && c <= 1000000000;
    //@ assert k >= 1 && k <= a + b + c;
    //@ assert a + b >= k;

    if (a < k) {
        min_val = a;
    } else {
        min_val = k;
    }
    //@ assert min_val == min_val(a, k);

    if (k - (a + b) > 0) {
        max_val = k - (a + b);
    } else {
        max_val = 0;
    }
    //@ assert max_val == max_val(a, b, k);

    ans = min_val - max_val;
    //@ assert ans == answer(a, b, k);

    //@ assert min_val >= 0;
    //@ assert max_val >= 0;
    //@ assert ans >= 0;
    //@ assert min_val <= k;
    //@ assert max_val <= k;
    //@ assert ans <= k;
    //@ assert min_val <= a;
    //@ assert ans <= a;

    return ans;
}
