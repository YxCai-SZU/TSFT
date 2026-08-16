#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        0 <= a && 0 <= b && 0 <= c &&
        1 <= k && k <= a + b + c &&
        k <= 2000000000;
*/

/*@
    logic integer compute_ans(integer a, integer b, integer c, integer k) =
        k < a ? k :
        k < a + b ? a :
        a - (k - a - b < c ? k - a - b : c);
*/

/*@
    lemma ans_bounds:
        \forall integer a, b, c, k;
        valid_params(a, b, c, k) ==> compute_ans(a, b, c, k) <= k;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result == compute_ans(a, b, c, k);
    ensures \result <= k;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t a_local = a;
    int32_t k_local = k;
    int32_t ans = 0;
    int32_t k2 = 0;

    //@ assert valid_params(a_local, b, c, k_local);
    
    if (k_local >= a_local)
    {
        ans += a_local;
        k_local -= a_local;
        //@ assert ans == a_local && k_local == k - a_local;
    }
    else
    {
        //@ assert k_local == k && k_local < a_local;
        return k_local;
    }

    //@ assert ans == a_local && k_local == k - a_local;
    
    if (k_local >= b)
    {
        k_local -= b;
        //@ assert k_local == k - a_local - b;
    }
    else
    {
        //@ assert k_local < b;
        return ans;
    }

    //@ assert k_local == k - a_local - b && ans == a_local;
    
    /*@
        loop invariant 0 <= k2 <= c;
        loop invariant 0 <= k_local <= k - a_local - b;
        loop invariant k2 == (k - a_local - b) - k_local;
        loop assigns k2, k_local;
        loop variant k_local;
    */
    while (k_local > 0 && k2 < c)
    {
        k2 += 1;
        k_local -= 1;
        //@ assert k2 <= c && k_local >= 0;
    }
    
    ans -= k2;
    //@ assert ans == a_local - k2;
    
    return ans;
}
