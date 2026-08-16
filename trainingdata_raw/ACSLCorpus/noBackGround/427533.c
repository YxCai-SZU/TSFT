#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(a + (0 .. n-1));
  requires ((n) > 0 && (n) <= 100 &&
      \forall size_t i; 0 <= i < (n) ==> 1 <= (a)[i] <= 100);
  assigns \nothing;
  ensures 0 <= \result <= (int)n;
*/
int func(size_t n, int* a) {
    int ans = 0;
    size_t i = 0;
    
    /*@
      loop invariant (0 <= (i) <= (n) &&
      0 <= (ans) <= (int)(i) &&
      (((n)) > 0 && ((n)) <= 100 &&
      \forall size_t i; 0 <= i < ((n)) ==> 1 <= ((a))[i] <= 100));
      loop assigns i, ans;
      loop variant n - i;
    */
    while (i < n) {
        int index = a[i];
        
        //@ assert 0 <= i < n;
        //@ assert 1 <= index <= 100;
        
        if ((i & 1) == 0 && (index & 1) == 1) {
            ans += 1;
        }
        
        i += 1;
        
        //@ assert i <= n;
    }
    
    //@ assert ans_bounds: 0 <= ans <= (int)n;
    return ans;
}
