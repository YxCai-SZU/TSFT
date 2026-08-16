#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= c && c <= 100 &&
        a + b + c <= 100 &&
        1 <= k && k <= a + b + c;

    logic integer compute_res(integer a, integer b, integer c, integer k) =
        k <= a ? k :
        a + b >= k ? a :
        a - (k - a - b);
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result <= k;
    ensures \result <= a;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t res;
    //@ assert valid_params(a, b, c, k);
    
    if (k <= a) {
        res = k;
        //@ assert res <= k;
    } else if (a + b >= k) {
        res = a;
        //@ assert res <= k;
    } else {
        res = a - (k - a - b);
        //@ assert res <= k;
    }
    
    //@ assert res <= a;
    return res;
}
