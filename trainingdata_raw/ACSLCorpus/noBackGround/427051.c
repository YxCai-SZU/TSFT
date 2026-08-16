#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) >= 1 && (n) <= 100 &&
      (m) >= 1 && (m) <= 100 &&
      (x) >= 1 && (x) < (n) && (x) <= (n) - 1);
  requires \valid(a + (0 .. m-1));
  requires ((m) == (m) &&
      \forall integer i; 0 <= i < (m) ==> 
        (a)[i] >= 1 && (a)[i] <= (n) && (a)[i] != (x));
  assigns \nothing;
  ensures 0 <= \result <= m;
*/
int func(int n, int m, int x, int *a) {
    int l = 0;
    int r = 0;
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= m;
      loop invariant l >= 0;
      loop invariant r >= 0;
      loop invariant l + r <= i;
      loop assigns i, l, r;
      loop variant m - i;
    */
    while (i < m) {
        int value = a[i];
        //@ assert value >= 1 && value <= n && value != x;
        
        if (value < x) {
            l = l + 1;
        }
        
        if (value > x) {
            r = r + 1;
        }
        
        i = i + 1;
        //@ assert l + r <= i;
    }
    
    //@ assert l + r <= m;
    
    if (l > r) {
        //@ assert 0 <= r <= m;
        return r;
    } else {
        //@ assert 0 <= l <= m;
        return l;
    }
}
