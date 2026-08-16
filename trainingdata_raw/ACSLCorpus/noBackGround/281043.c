#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) >= 1 && (n) <= 100 && (x) >= 1 && (x) <= 10000);
  requires \valid(l + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> (l)[i] >= 1 && (l)[i] <= 100);
  assigns \nothing;
  ensures \result >= 1 && \result <= n + 1;
*/
size_t func(size_t n, size_t x, size_t l[]) {
    size_t count = 1;
    size_t ans = 0;
    size_t i = 0;
    
    /*@
      loop invariant ((((n)) >= 1 && ((n)) <= 100 && ((x)) >= 1 && ((x)) <= 10000) &&
      (\forall integer i; 0 <= i < ((n)) ==> ((l))[i] >= 1 && ((l))[i] <= 100) &&
      0 <= (i) && (i) <= (n) &&
      (ans) <= (x) + 100 * (i) &&
      (count) >= 1 && (count) <= (i) + 1 &&
      ((i) > 0 ==> (\forall integer k; 0 <= k < (i) ==> (ans) >= (l)[k])));
      loop assigns i, ans, count;
      loop variant n - i;
    */
    while (i < n && ans <= x) {
        //@ assert i < n;
        ans += l[i];
        
        if (ans > x) {
            //@ assert count >= 1 && count <= i + 1;
            return count;
        }
        
        count += 1;
        i += 1;
        
        //@ assert ans <= x + 100 * i;
    }
    
    //@ assert count >= 1 && count <= n + 1;
    return n + 1;
}
