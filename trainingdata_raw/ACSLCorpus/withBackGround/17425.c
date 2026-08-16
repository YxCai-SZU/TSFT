#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_length(integer len) = 0 <= len < 0x80000000; */

/*@ lemma count_equals_i: 
      \forall integer i, integer count; 
      count == i ==> count <= i; */

/*@
  requires is_valid_length(length);
  ensures \result == (int)length;
*/
int count_list_elements(int *test_tup, size_t length)
{
    int count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= length;
      loop invariant count == (int)i;
      loop invariant is_valid_length(length);
      loop assigns count, i;
    */
    while (i < length) {
        //@ assert count == (int)i;
        count += 1;
        i += 1;
    }
    
    //@ assert count == (int)length;
    return count;
}
