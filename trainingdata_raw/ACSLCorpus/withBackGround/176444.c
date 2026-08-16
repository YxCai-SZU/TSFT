#include <stdint.h>

/*@
    predicate nonnegative(integer a, integer b, integer c, integer k) =
        a >= 0 && b >= 0 && c >= 0 && 1 <= k && k <= a + b + c && k <= 2000000000;

    logic integer compute_res(integer a, integer b, integer c, integer k) =
        \let rst1 = (a >= k) ? 0 : k - a;
        \let rst2 = (b >= rst1) ? 0 : rst1 - b;
        \let res1 = (a >= k) ? k : a;
        res1 - rst2;
*/

/*@
    lemma res_bound: \forall integer a, b, c, k;
        nonnegative(a, b, c, k) ==> compute_res(a, b, c, k) <= k;
*/

/*@
    requires nonnegative(a, b, c, k);
    ensures \result <= k;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t res = 0;
    int64_t rst = k;
    
    //@ assert rst == k;
    
    if (a >= rst) {
        //@ assert a >= rst;
        res += rst;
        rst -= rst;
        //@ assert rst == 0;
    } else {
        //@ assert a < rst;
        res += a;
        rst -= a;
        //@ assert rst == k - a;
    }
    
    //@ assert res <= k;
    
    if (b >= rst) {
        //@ assert b >= rst;
        rst -= rst;
        //@ assert rst == 0;
    } else {
        //@ assert b < rst;
        rst -= b;
        //@ assert rst == k - a - b;
    }
    
    //@ assert res - rst <= k;
    res -= rst;
    
    //@ assert res <= k;
    return res;
}
