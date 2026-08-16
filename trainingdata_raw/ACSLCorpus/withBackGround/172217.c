#include <limits.h>

/*@ predicate in_range(integer n, integer k) =
      1 <= n <= 1000000000 &&
      1 <= k <= n + 1;
*/

/*@ logic integer diff_val(integer n, integer k) =
      (k - 1 < 0) ? -(k - 1) : (k - 1);
*/

/*@ logic integer min_diff(integer n, integer k, integer d) =
      (d < n - k) ? d : (n - k);
*/

/*@ logic integer min_val(integer n, integer k, integer md) =
      (md < k - 1) ? md : (k - 1);
*/

/*@ lemma result_property:
      \forall integer n, k, ans;
      in_range(n, k) && ans == min_val(n, k, min_diff(n, k, diff_val(n, k))) ==>
      ans == k - 1 || ans == n - k;
*/

/*@ requires 1 <= n <= 1000000000;
    requires 1 <= k <= n + 1;
    ensures \result == k - 1 || \result == n - k;
    assigns \nothing;
*/
long func(long n, long k) {
    long diff;
    long min_diff_val;
    long min_val_result;
    long ans;

    //@ assert in_range(n, k);
    
    // Calculate absolute difference
    if (k - 1 < 0) {
        diff = -(k - 1);
    } else {
        diff = k - 1;
    }
    
    // Calculate minimum between diff and n-k
    if (diff < n - k) {
        min_diff_val = diff;
    } else {
        min_diff_val = n - k;
    }
    
    // Calculate minimum value
    if (min_diff_val < k - 1) {
        min_val_result = min_diff_val;
    } else {
        min_val_result = k - 1;
    }
    
    ans = min_val_result;
    
    //@ assert ans == k - 1 || ans == n - k;
    
    return ans;
}
