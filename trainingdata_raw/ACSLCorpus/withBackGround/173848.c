#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_params(integer n, integer m) =
      n >= 1 && n <= 100000 &&
      m >= 1 && m <= 100000;
*/

/*@ predicate valid_array(int *h, integer n) =
      \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 100;
*/

/*@
  requires valid_params(n, m);
  requires valid_array(h, n);
  requires \valid(h + (0 .. n-1));
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= n;
*/
int func(int n, int m, int *h) {
    int ans = 0;
    int acc = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= (size_t)n;
      loop invariant ans >= 0;
      loop invariant ans <= (int)index;
      loop invariant acc >= 0;
      loop invariant acc <= 100;
      loop invariant index <= n;
      loop assigns ans, acc, index;
      loop variant n - index;
    */
    while (index < (size_t)n) {
        int a = h[index];
        
        //@ assert a >= 1 && a <= 100;
        
        if (a >= acc && a >= m) {
            ans += 1;
            acc = a;
        }
        
        //@ assert ans >= 0;
        
        index += 1;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= n;
    return ans;
}
