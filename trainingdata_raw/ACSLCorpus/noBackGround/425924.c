#include <stddef.h>
#include <stdbool.h>

/*@
  requires ((n) > 0 && (n_q) > 0 &&
      \valid((arr) + (0 .. (n)-1)) && \valid((arr_s) + (0 .. (n_q)-1)));
  assigns \nothing;
  ensures \result <= n_q;
*/
size_t func(size_t n, int *arr, size_t n_q, int *arr_s) {
    size_t total = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n_q;
      loop invariant total <= i;
      loop invariant total <= n_q;
      loop assigns i, total;
      loop variant n_q - i;
    */
    while (i < n_q) {
        size_t j = 0;
        int found = 0;
        size_t old_total = total;
        
        /*@
          loop invariant 0 <= j <= n;
          loop invariant found == 0 || found == 1;
          loop invariant found == 1 ==> total == old_total + 1;
          loop invariant found == 0 ==> total == old_total;
          loop invariant total <= i+1;
          loop assigns j, total, found;
          loop variant n - j;
        */
        while (j < n && found == 0) {
            //@ assert 0 <= j < n && 0 <= i < n_q;
            if (arr[j] == arr_s[i]) {
                total += 1;
                found = 1;
            }
            j += 1;
        }
        i += 1;
    }
    return total;
}
