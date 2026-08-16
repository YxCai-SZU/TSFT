#include <stdbool.h>
#include <stddef.h>

/*@
  requires (3 <= (n) && (n) <= 100 &&
      1 <= (a) && (a) < (b) && (b) < 20);
  requires \valid(p + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= 20);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int func(int n, int a, int b, int *p) {
    int count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= (size_t)n;
      loop invariant 0 <= count <= (int)i;
      loop invariant count == (int)i;
      loop assigns i, count;
      loop variant (size_t)n - i;
    */
    while (i < (size_t)n) {
        int x = p[i];
        
        //@ assert 1 <= x && x <= 20;
        
        if (x <= a) {
            count += 1;
        } else if (x <= b) {
            count += 1;
        } else {
            count += 1;
        }
        
        i += 1;
    }
    
    return count;
}
