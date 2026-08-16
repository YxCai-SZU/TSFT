#include <stdbool.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= c && c <= 100 &&
        1 <= k && k <= 100 &&
        a + b + c >= k;

    logic integer compute_ans(integer a, integer b, integer c, integer k) =
        (k < a ? k : a) - (k - a - b > 0 ? k - a - b : 0) - (k - a - b - c > 0 ? k - a - b - c : 0);

    lemma ans_bounds: \forall integer a, b, c, k;
        valid_params(a, b, c, k) ==> compute_ans(a, b, c, k) >= -c && compute_ans(a, b, c, k) <= a;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result >= -c && \result <= a;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int ans = 0;
    
    //@ assert valid_params(a, b, c, k);
    
    if (k < a) {
        ans += k;
    } else {
        ans += a;
    }
    
    //@ assert ans >= -c && ans <= a;
    
    if (k - a - b > 0) {
        ans -= (k - a - b);
    } else {
        ans -= 0;
    }
    
    //@ assert ans >= -c && ans <= a;
    
    if (k - a - b - c > 0) {
        ans -= (k - a - b - c);
    } else {
        ans -= 0;
    }
    
    //@ assert ans >= -c && ans <= a;
    
    return ans;
}
