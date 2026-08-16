#include <stdint.h>
#include <stdbool.h>

/*@ predicate distinct_elements(int64_t* a, integer n) =
      \forall integer i, j; 0 <= i < j < n ==> a[i] != a[j];
*/

/*@ predicate valid_array(int64_t* a, integer n) =
      \forall integer i; 0 <= i < n ==> 1 <= a[i] <= n;
*/

/*@
  requires 2 <= k <= n <= 100000;
  requires \valid(a + (0..n-1));
  requires valid_array(a, n);
  requires distinct_elements(a, n);
  ensures \result <= n - 1;
*/
int64_t func(int64_t n, int64_t k, int64_t* a) {
    int64_t t;
    int64_t u;
    int64_t ans;
    
    if (n > k) {
        t = n - k;
        //@ assert t <= n - 1;
    } else {
        t = 0;
        //@ assert t <= n - 1;
    }
    
    u = k - 1;
    //@ assert u <= n - 1;
    
    if (t < u) {
        ans = t;
    } else {
        ans = u;
    }
    
    //@ assert ans <= n - 1;
    return ans;
}
