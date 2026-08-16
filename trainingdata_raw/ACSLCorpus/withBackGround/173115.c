#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

/*@
  predicate is_none_pred{L}(int *list, integer len) =
    \forall integer i; 0 <= i < len ==> list[i] == 0;
*/

/*@
  requires \valid(list+(0..len-1));
  requires len <= INT_MAX;
  assigns \nothing;
  ensures \result == true <==> is_none_pred(list, len);
*/
bool is_none(const int *list, size_t len) {
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer j; 0 <= j < i ==> list[j] == 0;
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (list[i] != 0) {
            return false;
        }
        i = i + 1;
    }
    return true;
}
