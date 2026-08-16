#include <stdbool.h>
#include <stddef.h>

/*@
  requires (2 <= (k) <= (n) <= 100);
  requires ((n) >= 2 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000);
  requires \valid(a + (0 .. n-1));
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int func(size_t n, size_t k, const int* a) {
    int ans = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= ans <= i;
      loop invariant (2 <= (k) <= (n) <= 100);
      loop invariant ((n) >= 2 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000);
      loop assigns i, ans;
      loop variant n - i;
    */
    while (i < n) {
        size_t cnt = 0;
        size_t j = 0;
        
        /*@
          loop invariant 0 <= j <= n;
          loop invariant 0 <= cnt <= j;
          loop invariant 0 <= i < n;
          loop invariant (2 <= (k) <= (n) <= 100);
          loop invariant ((n) >= 2 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000);
          loop assigns j, cnt;
          loop variant n - j;
        */
        while (j < n) {
            if (i == j) {
                j++;
                continue;
            }
            
            int diff;
            if (a[i] > a[j]) {
                diff = a[i] - a[j];
            } else {
                diff = a[j] - a[i];
            }
            
            //@ assert diff == ((a[i]) > (a[j]) ? (a[i]) - (a[j]) : (a[j]) - (a[i]));
            
            if (diff <= (int)k) {
                cnt++;
            }
            
            j++;
        }
        
        if (cnt >= k) {
            ans++;
        }
        
        i++;
    }
    
    //@ assert 0 <= ans <= n;
    return ans;
}
