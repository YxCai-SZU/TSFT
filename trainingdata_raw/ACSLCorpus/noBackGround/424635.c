#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(none_tup + (0..len-1));
  requires \valid(test_tup + (0..len-1));
  assigns \nothing;
  ensures \result == true ==> 
           (\forall integer i; 0 <= i < len ==> (none_tup[i] ? test_tup[i] == \null : test_tup[i] != \null));
*/
bool check_none(void **test_tup, bool *none_tup, size_t len) {
    size_t i = 0;
    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer k; 0 <= k < i ==> (none_tup[k] ? test_tup[k] == \null : test_tup[k] != \null);
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        if (none_tup[i]) {
            //@ assert none_tup[i] == true;
            if (test_tup[i] != NULL) {
                return false;
            }
        } else {
            //@ assert none_tup[i] == false;
            if (test_tup[i] == NULL) {
                return false;
            }
        }
        i++;
    }
    return true;
}
