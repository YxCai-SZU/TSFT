#include <stdbool.h>

/*@ predicate exists_five(int *a, integer len) =
      \exists integer i; 0 <= i < len && a[i] == 5;
*/

/*@
  requires \valid(a+(0..len-1));
  requires len > 0;
  assigns \nothing;
  ensures \result == true <==> exists_five(a, len);
*/
bool search(int *a, int len) {
    int i = 0;
    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer k; 0 <= k < i ==> a[k] != 5;
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        if (a[i] == 5) {
            return true;
        }
        i = i + 1;
    }
    return false;
}
