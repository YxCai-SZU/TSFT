#include <stddef.h>
#include <stdint.h>

/*@
  requires n <= 100000;
  requires k <= 500;
  requires \valid_read(h + (0 .. n-1));
  requires (\forall size_t i; 0 <= i < (n) ==> 1 <= (h)[i] && (h)[i] <= 500);
  assigns \nothing;
  ensures \result <= n;
*/
size_t func(size_t n, uint32_t k, uint32_t *h) {
    size_t count;
    size_t index;
    
    count = 0;
    index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= count <= index;
      loop invariant index <= n;
      loop assigns index, count;
      loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        if (h[index] >= k) {
            //@ assert h[index] >= k;
            count = count + 1;
        }
        //@ assert count <= index + 1;
        index = index + 1;
    }
    
    //@ assert count <= n;
    return count;
}
