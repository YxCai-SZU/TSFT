#include <stdbool.h>
#include <stddef.h>

/*@
  requires n > 0 && n <= 100000;
  requires \valid(a + (0..n-1));
  requires (\forall integer i; 0 <= i < (n) ==> (((a)[i]) > 0) && (a)[i] <= 1000000000);
  ensures \result >= 0 && \result <= n;
  assigns \nothing;
*/
size_t func(size_t n, int a[]) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant count >= 0;
      loop invariant count <= i;
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n) {
        bool is_divisible = false;
        size_t j = 1;
        
        /*@
          loop invariant 1 <= j <= n;
          loop invariant is_divisible == false || 
            (\exists integer k; 1 <= k < j && k != i && (((a[i]) % 2 == 0 && (a[k]) % 2 == 0) || ((a[i]) % 2 != 0 && (a[k]) % 2 != 0)));
          loop assigns j, is_divisible;
          loop variant n - j;
        */
        while (j < n) {
            if (i != j) {
                int ai = a[i];
                int aj = a[j];
                //@ assert ((ai) > 0) && ((aj) > 0);
                if ((ai % 2 == 0 && aj % 2 == 0) || (ai % 2 != 0 && aj % 2 != 0)) {
                    is_divisible = true;
                }
            }
            j += 1;
        }
        
        if (!is_divisible) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
