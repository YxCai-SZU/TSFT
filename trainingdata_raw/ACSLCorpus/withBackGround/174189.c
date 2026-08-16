#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(size_t n, long long *a) =
      n >= 1 && n <= 200000 &&
      \valid_read(a + (0 .. n-1)) &&
      \forall integer k; 0 <= k < n ==> a[k] >= 1 && a[k] <= 1000000000;
*/

/*@
  requires valid_array(n, a);
  ensures \result >= 0 && \result <= n;
  assigns \nothing;
*/
size_t func(size_t n, long long *a) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant count >= 0 && count <= i;
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n) {
        long long num = a[i];
        bool is_divisible = true;
        size_t j = 0;
        
        /*@
          loop invariant 0 <= j <= n;
          loop invariant is_divisible == \true || is_divisible == \false;
          loop invariant is_divisible == \true ==> 
            \forall integer k; 0 <= k < j && k != i ==> num % a[k] == 0;
          loop assigns j, is_divisible;
          loop variant n - j;
        */
        while (j < n) {
            if (i != j) {
                if (num % a[j] != 0) {
                    is_divisible = false;
                }
            }
            j++;
        }
        
        if (is_divisible) {
            count++;
        }
        i++;
    }
    return count;
}
