#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) >= 1 && (n) <= 100000 &&
      (k) >= 1 && (k) <= 500 &&
      \valid((h) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
  ensures \result >= 0 && \result <= n;
  assigns \nothing;
*/
int func(int n, int k, int *h) {
    int count = 0;
    size_t index = 0;
    
    /*@
      loop invariant ((((n)) >= 1 && ((n)) <= 100000 &&
      ((k)) >= 1 && ((k)) <= 500 &&
      \valid(((h)) + (0 .. ((n))-1)) &&
      \forall integer i; 0 <= i < ((n)) ==> ((h))[i] >= 1 && ((h))[i] <= 500) &&
      0 <= (index) <= (n) &&
      0 <= (count) <= (index) &&
      (count) >= 0 &&
      (index) <= (n));
      loop assigns count, index;
      loop variant n - index;
    */
    while (index < (size_t)n) {
        int i = h[index];
        if (i >= k) {
            count += 1;
        }
        index += 1;
    }
    return count;
}
