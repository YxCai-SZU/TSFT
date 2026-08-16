#include <stddef.h>
#include <stdbool.h>

/*@
  requires \valid_read(test_tup + (0..len-1));
  requires len <= 0xFFFFFFFF;
  assigns \nothing;
  ensures \result <= len;
*/
size_t count_negative(const int *test_tup, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
      loop invariant ((i) <= (len) && (count) <= (i));
      loop invariant 0 <= i <= len;
      loop invariant 0 <= count <= i;
      loop assigns i, count;
      loop variant ((len) - (i));
    */
    while (i < len) {
        //@ assert i < len;
        if (test_tup[i] < 0) {
            //@ assert test_tup[i] < 0;
            count = count + 1;
        }
        i = i + 1;
    }
    //@ assert i == len;
    //@ assert count <= len;
    return count;
}
