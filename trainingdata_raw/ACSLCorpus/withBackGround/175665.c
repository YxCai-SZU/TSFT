#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_params(integer n, integer k) =
     1 <= n && n <= 100000 &&
     1 <= k && k <= 500;

   predicate valid_array(integer n, int *h) =
     \valid(h + (0 .. n-1)) &&
     \forall integer i; 0 <= i < n ==> 1 <= h[i] && h[i] <= 500;

   predicate count_condition(integer cnt, integer k, int val) =
     (val >= k ==> cnt >= 1) && (val < k ==> cnt >= 0);

   lemma cnt_bounds: \forall integer cnt, integer idx;
     0 <= cnt <= idx ==> cnt >= 0 && cnt <= idx;
*/

/*@
  requires valid_params(n, k);
  requires valid_array(n, h);
  ensures \result >= 0 && \result <= n;
  ensures \forall integer i; 0 <= i < n ==> 
          count_condition(\result, k, h[i]);
*/
long func(long n, long k, int *h) {
    long cnt = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= cnt <= index;
      loop invariant index > 0 ==> 
        \forall integer i; 0 <= i < index ==> 
          count_condition(cnt, k, h[i]);
      loop invariant valid_array(n, h);
      loop invariant valid_params(n, k);
      loop invariant cnt <= (long)index;
      loop invariant (long)index <= n;
      loop assigns cnt, index;
    */
    while (index < (size_t)n) {
        int x = h[index];
        if (x >= k) {
            cnt += 1;
        }
        index += 1;
    }
    return cnt;
}
