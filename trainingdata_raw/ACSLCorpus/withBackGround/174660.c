#include <limits.h>

/*@ predicate valid_params(integer n, integer k, integer x, integer y) =
      1 <= n <= 10000 &&
      1 <= k <= 10000 &&
      1 <= y < x <= 10000;
*/

/*@ lemma n_times_x_nonnegative:
      \forall integer n, integer x;
        1 <= n <= 10000 && 1 <= x <= 10000 ==> n * x >= 0;
*/

/*@ lemma kx_plus_remainder_nonnegative:
      \forall integer n, integer k, integer x, integer y;
        valid_params(n, k, x, y) && n > k ==> k * x + (n - k) * y >= 0;
*/

/*@ requires valid_params(n, k, x, y);
    ensures \result >= 0;
    ensures \result == n * x || \result == k * x + (n - k) * y;
    assigns \nothing;
*/
int func(int n, int k, int x, int y) {
    int result;
    
    if (n <= k) {
        //@ assert n * x >= 0;
        result = n * x;
    } else {
        //@ assert k * x + (n - k) * y >= 0;
        result = k * x + (n - k) * y;
    }
    
    return result;
}
