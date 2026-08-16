#include <stddef.h>
#include <stdbool.h>

/*@
  requires \valid_read(listval + (0..len-1));
  requires len > 0;
  assigns \nothing;
  ensures \result <= len;
*/
size_t count_odd(const int *listval, size_t len) {
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
        if ((listval[i] & 1) != 0) {
            count = count + 1;
        }
        i = i + 1;
    }
    
    //@ assert count <= len;
    return count;
}
