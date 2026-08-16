#include <stdbool.h>
#include <stdint.h>

/*@ predicate valid_array(uint32_t *arr, integer len) =
      len >= 1 && len <= 100000 &&
      \forall integer j; 0 <= j < len ==> arr[j] > 0 && arr[j] <= 1000000000;
*/

/*@ logic integer absolute_diff(integer a, integer b) =
      a > b ? a - b : b - a;
*/

/*@ lemma ans_bound:
      \forall integer len, integer i, uint32_t *arr, integer ans;
      valid_array(arr, len) && 0 <= i <= len-1 && ans <= 1000000000 ==>
      (i < len-1 ==> absolute_diff(arr[i], arr[i+1]) <= 1000000000);
*/

/*@ requires n >= 1 && n <= 100000;
    requires valid_array(x, n);
    assigns \nothing;
    ensures \result <= 1000000000;
*/
uint32_t func(uint32_t *x, uint32_t n) {
    // Variable declarations
    uint32_t ans;
    uint32_t i;
    uint32_t diff;

    ans = 1000000000;
    i = 0;

    /*@ loop invariant 0 <= i <= n-1;
        loop invariant ans <= 1000000000;
        loop invariant \forall integer k; 0 <= k < i ==> 
            ans <= absolute_diff(x[k], x[k+1]);
        loop assigns ans, i, diff;
        loop variant n - 1 - i;
    */
    while (i < n - 1) {
        if (x[i] > x[i + 1]) {
            diff = x[i] - x[i + 1];
        } else {
            diff = x[i + 1] - x[i];
        }
        
        //@ assert diff == absolute_diff(x[i], x[i+1]);
        
        if (ans > diff) {
            ans = diff;
        }
        
        i += 1;
    }
    
    return ans;
}
