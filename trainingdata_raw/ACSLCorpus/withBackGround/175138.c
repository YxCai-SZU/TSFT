#include <stdint.h>

/*@ predicate valid_params(integer a, integer b, integer c, integer k) =
   1 <= a && a <= 100 &&
   1 <= b && b <= 100 &&
   1 <= c && c <= 100 &&
   1 <= k && k <= 100;
*/

/*@ logic integer compute_ans(integer a, integer b, integer c, integer k) =
   a <= k ?
   (b <= k - a ?
    (c <= k - a - b ? a - c : a - (k - a - b))
    : a)
   : k;
*/

/*@ lemma ans_bounds:
   \forall integer a, b, c, k;
   valid_params(a, b, c, k) ==>
   compute_ans(a, b, c, k) >= -c &&
   compute_ans(a, b, c, k) <= a &&
   compute_ans(a, b, c, k) <= k;
*/

/*@
 requires valid_params(a, b, c, k);
 ensures \result >= -c && \result <= a && \result <= k;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t ans = 0;
    int64_t rst = k;

    //@ assert rst == k;
    //@ assert ans == 0;

    if (a <= rst) {
        ans += a;
        rst -= a;
        //@ assert ans == a;
        //@ assert rst == k - a;

        if (b <= rst) {
            rst -= b;
            //@ assert rst == k - a - b;

            if (c <= rst) {
                ans -= c;
                //@ assert ans == a - c;
            } else {
                ans -= rst;
                //@ assert ans == a - (k - a - b);
            }
        } else {
            rst -= rst;
            //@ assert rst == 0;
            //@ assert ans == a;
        }
    } else {
        //@ assert ans == 0;
        //@ assert rst == k;
        return k;
    }

    //@ assert ans >= -c && ans <= a && ans <= k;
    return ans;
}
