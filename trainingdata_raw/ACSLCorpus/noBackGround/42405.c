#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) > 0 && (n) <= 100 &&
      \forall size_t i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 100);
  ensures \result >= 0 && \result <= (int)n;
*/
int func(size_t n, int *a)
{
    int count = 0;
    size_t index = 0;
    
    //@ assert ((index) <= (n) &&       (count) >= 0 &&       (count) <= (int)(index) &&       ((index) > 0 ==> \forall size_t i; 0 <= i < (index) ==> 1 <= (a)[i] && (a)[i] <= 100));
    
    /*@ loop invariant ((index) <= (n) &&
      (count) >= 0 &&
      (count) <= (int)(index) &&
      ((index) > 0 ==> \forall size_t i; 0 <= i < (index) ==> 1 <= (a)[i] && (a)[i] <= 100));
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n) {
        int i = a[index];
        int ans = ((index & 1) == 0 && (i & 1) == 1) ? 1 : 0;
        count += ans;
        index += 1;
        
        //@ assert index <= n;
        //@ assert count <= (int)n;
    }
    
    return count;
}
