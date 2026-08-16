#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_odd(integer x) = (x % 2) != 0; */

/*@
  requires \valid(list1 + (0..len-1));
  requires len > 0;
  assigns \nothing;
  ensures \result <= len;
*/
size_t count_odd(const int *list1, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
      loop invariant i <= len;
      loop invariant count <= i;
      loop assigns i, count;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert i < len;
        if ((list1[i] & 1) != 0) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
