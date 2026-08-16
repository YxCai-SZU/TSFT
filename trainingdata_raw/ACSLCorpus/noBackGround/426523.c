#include <stddef.h>

/*@
  requires \valid_read(list1 + (0..len-1));
  requires len > 0;
  assigns \nothing;
  ensures 0 <= \result <= len;
*/
size_t count_even_odd(const int *list1, size_t len) {
    size_t even_count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant 0 <= even_count <= i;
      loop invariant \forall integer k; 0 <= k < i ==> 
                     (list1[k] % 2 == 0) ==> even_count > 0;
      loop assigns i, even_count;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert even_count <= i;
        if (list1[i] % 2 == 0) {
            even_count += 1;
        }
        i += 1;
        //@ assert even_count <= i;
    }
    return even_count;
}
