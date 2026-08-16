#include <stddef.h>

/*@
  requires ((n) > 0 && (k) > 0 && (n) == (n)) && (\forall size_t i; 0 <= i < (n) ==> (h)[i] > 0);
  ensures ((\result) <= (n) &&
      \forall size_t i; 0 <= i < (n) ==> ((h)[i] >= (int)(k) ==> (\result) > 0));
*/
size_t func(size_t n, size_t k, int *h)
{
    size_t count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= count <= i;
      loop invariant i > 0 ==> \forall size_t j; 0 <= j < i ==> (h[j] >= (int)k ==> count > 0);
      loop assigns i, count;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (h[i] >= (int)k) {
            //@ assert h[i] >= (int)k;
            count += 1;
            //@ assert count > 0;
        }
        i += 1;
        //@ assert \forall size_t j; 0 <= j < i ==> (h[j] >= (int)k ==> count > 0);
    }
    
    //@ assert ((count) <= (n) &&       \forall size_t i; 0 <= i < (n) ==> ((h)[i] >= (int)(k) ==> (count) > 0));
    return count;
}
