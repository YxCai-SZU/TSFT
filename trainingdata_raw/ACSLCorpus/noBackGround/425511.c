#include <stdbool.h>
#include <stddef.h>

/*@
  requires 1 <= n <= 100000;
  requires 1 <= m <= 100000;
  requires \valid(a + (0..n-1));
  requires \valid(b + (0..m-1));
  requires (\forall integer k; 0 <= k < (n) ==> 0 <= (a)[k] <= 1000000000);
  requires (\forall integer k; 0 <= k < (m) ==> 0 <= (b)[k] <= 1000000000);
  ensures \result >= 0;
  ensures \result <= n;
*/
int func(int n, int m, int *a, int *b) {
    int ans = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= (size_t)n;
      loop invariant 0 <= ans <= (int)i;
      loop invariant (\forall integer k; 0 <= k < (n) ==> 0 <= (a)[k] <= 1000000000);
      loop invariant (\forall integer k; 0 <= k < (m) ==> 0 <= (b)[k] <= 1000000000);
      loop invariant 1 <= n <= 100000;
      loop invariant 1 <= m <= 100000;
      loop assigns ans, i;
      loop variant n - i;
    */
    while (i < (size_t)n) {
        size_t j = 0;
        bool found = false;
        
        /*@
          loop invariant 0 <= j <= (size_t)m;
          loop invariant ans == \at(ans, LoopEntry);
          loop invariant (\forall integer k; 0 <= k < (n) ==> 0 <= (a)[k] <= 1000000000);
          loop invariant (\forall integer k; 0 <= k < (m) ==> 0 <= (b)[k] <= 1000000000);
          loop invariant 1 <= n <= 100000;
          loop invariant 1 <= m <= 100000;
          loop assigns j, ans, found;
          loop variant m - j;
        */
        while (j < (size_t)m) {
            if (a[i] == b[j]) {
                ans++;
                found = true;
                break;
            }
            j++;
        }
        
        if (!found) {
            break;
        }
        i++;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= n;
    return ans;
}
