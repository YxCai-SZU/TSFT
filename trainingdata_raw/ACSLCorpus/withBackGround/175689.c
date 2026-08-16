#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_params(integer n, integer k) =
      n >= 1 && n <= 100000 &&
      k >= 1 && k <= 500;
*/

/*@ predicate valid_array(integer n, long *h) =
      \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 500;
*/

/*@ lemma bounds_preserved:
      \forall integer n, integer k, long *h;
      valid_params(n, k) && valid_array(n, h) ==>
      \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 500;
*/

/*@
  requires valid_params(n, k);
  requires \valid(h + (0 .. n-1));
  requires valid_array(n, h);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
long func(size_t n, const long *h, size_t k) {
    long ans = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= ans <= i;
      loop invariant valid_params(n, k);
      loop invariant valid_array(n, h);
      loop assigns ans, i;
      loop variant n - i;
    */
    while (i < n) {
        long hi = h[i];
        bool is_cnt = false;
        size_t j = 0;
        
        /*@
          loop invariant 0 <= j <= k;
          loop invariant is_cnt == false ==> j <= k;
          loop invariant is_cnt == true ==> hi <= (long)(j-1);
          loop invariant valid_params(n, k);
          loop invariant valid_array(n, h);
          loop assigns j, is_cnt;
          loop variant k - j;
        */
        while (j < k) {
            if (hi <= (long)j) {
                is_cnt = true;
                break;
            }
            j++;
        }
        
        if (is_cnt) {
            ans++;
        }
        i++;
    }
    return ans;
}
