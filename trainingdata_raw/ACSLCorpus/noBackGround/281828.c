#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) >= 1 && (n) <= 100000 &&
      (k) >= 1 && (k) <= 500);
  requires \valid(h + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int func(int n, int k, int *h) {
    int ans = 0;
    int index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= ans <= index;
      loop invariant index > 0 ==> (\forall integer i; 0 <= i < (index) ==> (h)[i] >= 1 && (h)[i] <= 500);
      loop invariant ((n) >= 1 && (n) <= 100000 &&
      (k) >= 1 && (k) <= 500);
      loop invariant (\forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
      loop assigns ans, index;
      loop variant n - index;
    */
    while (index < n) {
        int a = h[index];
        if (a >= k) {
            ans += 1;
        }
        index += 1;
        //@ assert ans <= index;
    }
    return ans;
}
