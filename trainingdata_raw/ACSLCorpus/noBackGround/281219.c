#include <stdbool.h>
#include <stddef.h>

/*@
  requires n >= 1 && n <= 100;
  requires n <= len && len <= 100;
  requires ((len) >= 1 && (len) <= 100 &&
      \forall size_t i; 0 <= i < (len) ==> (a)[i] >= 1 && (a)[i] <= 100);
  ensures \result >= 0;
  ensures \result <= (int)n;
  assigns \nothing;
*/
int func(size_t n, int *a, size_t len) {
    int count = 0;
    size_t index = 0;
    
    /*@
      loop invariant ((index) <= (n) && (index) <= (len));
      loop invariant ((count) >= 0 && (count) <= (int)(index));
      loop invariant ((len) >= 1 && (len) <= 100 &&
      \forall size_t i; 0 <= i < (len) ==> (a)[i] >= 1 && (a)[i] <= 100);
      loop invariant n >= 1 && n <= 100;
      loop invariant n <= len && len <= 100;
      loop assigns count, index;
      loop variant n - index;
    */
    while (index < n && index < len) {
        int i = a[index];
        //@ assert i >= 1 && i <= 100;
        
        if (index % 2 == 0 && i % 2 == 1) {
            //@ assert count >= 0 && count <= (int)index;
            count += 1;
            //@ assert count >= 0 && count <= (int)(index + 1);
        }
        
        index += 1;
        //@ assert index <= n && index <= len;
    }
    
    return count;
}
