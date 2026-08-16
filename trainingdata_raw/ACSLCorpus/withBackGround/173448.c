#include <limits.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        1 <= a && 1 <= b && 1 <= c &&
        a + b + c <= 200000 &&
        1 <= k && k <= a + b + c;

    logic integer compute_acnt(integer a, integer k) =
        a < k ? a : k;

    logic integer compute_bcnt(integer a, integer b, integer k) =
        b < k - compute_acnt(a, k) ? b : k - compute_acnt(a, k);

    logic integer compute_ccnt(integer a, integer b, integer k) =
        k - compute_acnt(a, k) - compute_bcnt(a, b, k);

    lemma acnt_bounds:
        \forall integer a, k;
        valid_params(a, 1, 1, k) ==>
        0 <= compute_acnt(a, k) && compute_acnt(a, k) <= k;

    lemma bcnt_bounds:
        \forall integer a, b, k;
        valid_params(a, b, 1, k) ==>
        0 <= compute_bcnt(a, b, k) && compute_bcnt(a, b, k) <= k;

    lemma ccnt_bounds:
        \forall integer a, b, k;
        valid_params(a, b, 1, k) ==>
        0 <= compute_ccnt(a, b, k) && compute_ccnt(a, b, k) <= k;

    lemma sum_equals_k:
        \forall integer a, b, k;
        valid_params(a, b, 1, k) ==>
        compute_acnt(a, k) + compute_bcnt(a, b, k) + compute_ccnt(a, b, k) == k;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result >= -k;
    ensures \result <= k;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int acnt;
    int bcnt;
    int ccnt;
    int res;

    //@ assert valid_params(a, b, c, k);
    
    // Calculate acnt
    if (a < k)
    {
        acnt = a;
    }
    else
    {
        acnt = k;
    }
    //@ assert acnt == compute_acnt(a, k);
    
    // Calculate bcnt
    if (b < k - acnt)
    {
        bcnt = b;
    }
    else
    {
        bcnt = k - acnt;
    }
    //@ assert bcnt == compute_bcnt(a, b, k);
    
    // Calculate ccnt
    ccnt = k - acnt - bcnt;
    //@ assert ccnt == compute_ccnt(a, b, k);
    
    // Calculate result
    res = acnt;
    if (ccnt > bcnt)
    {
        res -= ccnt - bcnt;
    }
    else
    {
        res -= ccnt;
    }
    
    // Final verification
    //@ assert res >= -k;
    //@ assert res <= k;
    
    return res;
}
