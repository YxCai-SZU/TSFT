#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_index(integer i, integer len) =
      0 <= i && i < len;
*/

/*@ predicate element_in_range(int *a, integer len, integer low, integer high) =
      \forall integer i; 0 <= i < len ==> low <= a[i] && a[i] <= high;
*/

/*@ predicate exists_zero(int *a, integer len) =
      \exists integer i; 0 <= i < len && a[i] == 0;
*/

/*@ predicate no_zero_before(int *a, integer idx) =
      \forall integer j; 0 <= j < idx ==> a[j] != 0;
*/

/*@ lemma zero_exists_in_remaining:
      \forall int *a, integer len, integer idx;
        exists_zero(a, len) && no_zero_before(a, idx) && idx <= len ==>
        \exists integer i; idx <= i && i < len && a[i] == 0;
*/

/*@
  requires len == 5;
  requires element_in_range(x, len, 0, 100);
  requires exists_zero(x, len);
  ensures \result >= 0;
  ensures \result < len;
  ensures x[\result] == 0;
*/
int func(int *x, int len)
{
    int index = 0;
    
    /*@
      loop invariant 0 <= index;
      loop invariant index <= len;
      loop invariant len == 5;
      loop invariant element_in_range(x, len, 0, 100);
      loop invariant exists_zero(x, len);
      loop invariant no_zero_before(x, index);
      loop assigns index;
    */
    while (index < len) {
        //@ assert index < len;
        if (x[index] == 0) {
            //@ assert x[index] == 0;
            return index;
        }
        //@ assert x[index] != 0;
        index++;
        //@ assert no_zero_before(x, index);
    }
    
    //@ assert false;
    return -1;
}
