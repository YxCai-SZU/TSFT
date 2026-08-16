#include <stdbool.h>

/*@
  requires 1 <= n <= 100000;
  requires 1 <= k <= 500;
  requires \valid(heights + (0..n-1));
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= *((heights) + i) <= 500);
  ensures \result >= 0 && \result <= n;
  ensures \forall integer i; 0 <= i < n ==> (*(heights + i) >= k ==> \result >= 1);
  ensures \forall integer i; 0 <= i < n ==> (*(heights + i) < k ==> \result >= 0);
*/
int func(int n, int k, int *heights) {
    int cnt = 0;
    int a = 0;
    unsigned int index = 0;
    /*@
      loop invariant 0 <= a <= n;
      loop invariant 0 <= index <= (unsigned int)n;
      loop invariant index == (unsigned int)a;
      loop invariant ((cnt) >= 0 && (cnt) <= (a) &&
      (\forall integer i; 0 <= i < (a) ==> (*((heights) + i) >= (k) ==> (cnt) >= 1)) &&
      (\forall integer i; 0 <= i < (a) ==> (*((heights) + i) < (k) ==> (cnt) >= 0)));
      loop assigns cnt, a, index;
      loop variant n - a;
    */
    while (a < n) {
        int hi = heights[index];
        if (hi >= k) {
            cnt += 1;
        }
        a += 1;
        index += 1;
    }
    return cnt;
}
