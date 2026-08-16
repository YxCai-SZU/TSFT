#include <stdbool.h>
#include <stddef.h>

/*@
  requires n > 0 && n <= 100;
  requires \valid(a + (0 .. n-1));
  requires ((n) > 0 && (n) <= 100 &&
      \forall size_t i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 100);
  assigns \nothing;
  ensures 0 <= \result && \result <= n;
*/
int func(size_t n, int *a) {
    int count = 0;
    size_t num = 0;
    
    /*@
      loop invariant (0 <= (num) && (num) <= (n) &&
      0 <= (count) && (count) <= (num) &&
      (((n)) > 0 && ((n)) <= 100 &&
      \forall size_t i; 0 <= i < ((n)) ==> 1 <= ((a))[i] && ((a))[i] <= 100));
      loop invariant n - num >= 0;
      loop assigns count, num;
      loop variant n - num;
    */
    while (num < n) {
        int ai = a[num];
        
        //@ assert count <= num;
        
        if ((num + 1) % 2 != 0 && (ai & 1) != 0) {
            count += 1;
        }
        
        num += 1;
        
        //@ assert count <= num;
    }
    
    return count;
}
