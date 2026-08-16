#include <stdbool.h>
#include <stddef.h>

/*@
  requires n >= 1 && n <= 1000000;
  requires m >= 1 && m <= 10000;
  requires \valid(a + (0 .. m-1));
  requires (\forall integer i; 0 <= i < (m) ==> 1 <= (a)[i] <= 10000);
  assigns \nothing;
  ensures \result >= -1;
  ensures \result <= n;
*/
int func(int n, int m, int *a) {
    int ret = n;
    int i = 0;
    
    /*@
      loop invariant (0 <= (i) <= (m) &&
      (ret) >= -1 &&
      (ret) <= (n) &&
      \forall integer j; 0 <= j < (i) ==> 1 <= (a)[j] <= 10000 &&
      (n) >= 1 && (n) <= 1000000 &&
      (m) >= 1 && (m) <= 10000 &&
      (ret) <= (n));
      loop assigns i, ret;
      loop variant m - i;
    */
    while (i < m) {
        int ai = a[i];
        //@ assert ai >= 1 && ai <= 10000;
        if (ret < ai) {
            return -1;
        }
        ret = ret - ai;
        i = i + 1;
    }
    return ret;
}
