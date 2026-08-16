#include <stdbool.h>
#include <stddef.h>

/*@ predicate all_unique(unsigned int *a, integer len) =
      \forall integer i, j; 0 <= i < j < len ==> a[i] != a[j];
*/

/*@ lemma unique_preserved:
      \forall unsigned int *a, integer len, integer bound;
        0 <= bound <= len && all_unique(a, len) ==> all_unique(a, bound);
*/

/*@
  requires \valid_read(v + (0 .. len-1));
  requires all_unique(v, len);
  assigns \nothing;
  ensures \result == (len % 2 == 1);
*/
bool find_element(unsigned int *v, size_t len) {
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant all_unique(v, i);
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        i++;
    }
    
    //@ assert i == len;
    return (len % 2 == 1);
}
