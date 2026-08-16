#include <stdbool.h>
#include <stddef.h>

/*@
  requires 1 <= n && n <= 100000;
  requires \valid(a + (0 .. n-1));
  requires (\forall integer k; 0 <= k < (n) ==> (a)[k] > 0);
  ensures \result == true <==> (\forall integer i; 0 <= i < (n) ==> 
        ((a)[i] % 2 != 0 || (a)[i] % 3 == 0 || (a)[i] % 5 == 0));
  assigns \nothing;
*/
bool func(size_t n, int *a) {
    bool ans = true;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant ans == true <==> 
        (\forall integer j; 0 <= j < i ==> 
          (a[j] % 2 != 0 || a[j] % 3 == 0 || a[j] % 5 == 0));
      loop assigns i, ans;
      loop variant n - i;
    */
    while (i < n) {
        int value = a[i];
        //@ assert value > 0;
        if (value % 2 == 0 && value % 3 != 0 && value % 5 != 0) {
            ans = false;
        }
        i += 1;
    }
    return ans;
}
