#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(integer n, int *a) =
      n >= 2 && n <= 100000 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer k; 0 <= k < n ==> a[k] >= 1 && a[k] <= 1000000000;
*/

/*@ predicate loop1_invariant(integer i, integer n, integer ret, int *a) =
      0 <= i && i <= n &&
      0 <= ret && ret <= (int)i &&
      valid_array(n, a);
*/

/*@ predicate loop2_invariant(integer i, integer j, integer n, integer ret, int *a) =
      1 <= j && j <= n &&
      0 <= ret && ret <= (int)i &&
      valid_array(n, a) &&
      i < n;
*/

/*@ lemma ret_bounds: \forall integer ret, integer n;
      (0 <= ret && ret <= (int)n) ==> ret >= -1 && ret <= (int)n;
*/

/*@
  requires valid_array(n, a);
  assigns \nothing;
  ensures \result >= -1 && \result <= (int)n;
*/
int func(size_t n, const int a[]) {
    int ret = 0;
    size_t i = 0;
    
    /*@
      loop invariant loop1_invariant(i, n, ret, a);
      loop assigns i, ret;
      loop variant n - i;
    */
    while (i < n) {
        bool is_divisible = false;
        size_t j = 1;
        
        /*@
          loop invariant loop2_invariant(i, j, n, ret, a);
          loop assigns j, is_divisible;
          loop variant n - j;
        */
        while (j < n) {
            //@ assert 0 <= i && i < n && 0 <= j && j < n;
            if (i != j && a[i] % a[j] == 0) {
                is_divisible = true;
                break;
            }
            j++;
        }
        
        if (!is_divisible) {
            //@ assert ret >= 0 && ret <= (int)i;
            ret++;
            //@ assert ret >= 0 && ret <= (int)(i+1);
        }
        i++;
    }
    
    //@ assert ret >= 0 && ret <= (int)n;
    if (ret == (int)n) {
        return -1;
    } else {
        return ret;
    }
}
