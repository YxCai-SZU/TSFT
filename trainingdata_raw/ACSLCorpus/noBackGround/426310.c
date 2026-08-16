#include <stdbool.h>

/*@
  requires n >= 1 && n <= 20;
  requires ((n) >= 1 && (n) <= 20 &&
      \forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 100);
  ensures \result >= 0 && \result <= n;
*/
int func(int n, int *h) {
    int max = 0;
    int cnt = 0;
    int i = 0;
    
    /*@
      loop invariant (0 <= (i) <= (n) &&
      0 <= (cnt) <= (i) &&
      (max) >= 0 &&
      (max) <= 100 &&
      (((n)) >= 1 && ((n)) <= 20 &&
      \forall integer i; 0 <= i < ((n)) ==> ((h))[i] >= 1 && ((h))[i] <= 100));
      loop assigns i, cnt, max, h[0..n-1];
      loop variant n - i;
    */
    while (i < n) {
        bool all_less_or_equal = true;
        int j = 0;
        
        /*@
          loop invariant (0 <= (j) <= (i) &&
      (((n)) >= 1 && ((n)) <= 20 &&
      \forall integer i; 0 <= i < ((n)) ==> ((h))[i] >= 1 && ((h))[i] <= 100) &&
      (i) < (n));
          loop assigns j, all_less_or_equal;
          loop variant i - j;
        */
        while (j < i) {
            //@ assert 0 <= i < n && 0 <= j < n;
            if (h[i] < h[j]) {
                all_less_or_equal = false;
            }
            j++;
        }
        
        if (all_less_or_equal) {
            cnt++;
            max = h[i];
        }
        i++;
    }
    return cnt;
}
