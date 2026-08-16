#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) >= 1 && (n) <= 100000 &&
      (k) >= 1 && (k) <= 500 &&
      \valid((h) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (h)[i] && (h)[i] <= 500);
  assigns \nothing;
  ensures \result >= 0 && \result <= n;
  ensures \forall integer i; 0 <= i < n ==> (k <= h[i] ==> \result > 0);
*/
long func(long n, long k, int *h) {
    long count = 0;
    long index = 0;
    
    /*@
      loop invariant ((index) >= 0 && (index) <= (n) &&
      (count) >= 0 && (count) <= (index) &&
      (count) <= (n) &&
      ((index) > 0 ==> \forall integer i; 0 <= i < (index) ==> ((k) <= (h)[i] ==> (count) > 0)));
      loop invariant ((n) >= 1 && (n) <= 100000 &&
      (k) >= 1 && (k) <= 500 &&
      \valid((h) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (h)[i] && (h)[i] <= 500);
      loop assigns count, index;
      loop variant n - index;
    */
    while (index < n) {
        int hi = h[index];
        if (k <= hi) {
            //@ assert k <= hi;
            count = count + 1;
        }
        index = index + 1;
    }
    return count;
}
