#include <stddef.h>

/*@
  requires ((n) >= 1 && (n) <= 200 &&
      (k) >= 1 && (k) <= 200);
  requires (\valid_read((numbers) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 1000);
  ensures \result >= 0 && \result <= n;
  assigns \nothing;
*/
size_t func(size_t n, size_t k, size_t *numbers) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= count <= i;
      loop assigns count, i;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert i < n;
        if (numbers[i] < k) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
