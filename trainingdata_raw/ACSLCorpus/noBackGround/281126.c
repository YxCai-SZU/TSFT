#include <stdbool.h>
#include <stddef.h>

/*@
  requires n >= 1 && n <= 100000;
  requires n_q >= 1 && n_q <= 100000;
  requires \valid(arr + (0 .. n-1));
  requires \valid(arr_s + (0 .. n_q-1));
  requires ((n) >= 1 && (n) <= 100000 &&
      \forall integer k; 0 <= k < (n) ==> (arr)[k] >= 1 && (arr)[k] <= 1000000000);
  requires ((n_q) >= 1 && (n_q) <= 100000 &&
      \forall integer k; 0 <= k < (n_q) ==> (arr_s)[k] >= 1 && (arr_s)[k] <= 1000000000);
  assigns \nothing;
  ensures 0 <= \result <= n_q;
*/
int func(int n, int *arr, int n_q, int *arr_s) {
    int total = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= (size_t)n_q;
      loop invariant 0 <= total <= i;
      loop assigns i, total;
      loop variant n_q - i;
    */
    while (i < (size_t)n_q) {
        size_t j = 0;
        bool found = false;
        int old_total = total;
        
        /*@
          loop invariant 0 <= j <= (size_t)n;
          loop invariant !found ==> \forall integer k; 0 <= k < j ==> arr_s[i] != arr[k];
          loop invariant found ==> \exists integer k; 0 <= k < j && arr_s[i] == arr[k];
          loop invariant total == old_total + (found ? 1 : 0);
          loop assigns j, found, total;
          loop variant n - j;
        */
        while (j < (size_t)n && !found) {
            if (arr_s[i] == arr[j]) {
                total += 1;
                found = true;
            }
            j += 1;
        }
        i += 1;
    }
    return total;
}
