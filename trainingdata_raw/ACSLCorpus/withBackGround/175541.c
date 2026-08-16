#include <stdbool.h>

/*@ predicate sorted(int *a, integer len) =
      \forall integer i; 0 <= i < len - 1 ==> a[i] <= a[i + 1];
*/

/*@
  requires \valid_read(a + (0 .. len-1));
  requires len < 0x80000000;
  assigns \nothing;
  ensures \result == true <==> sorted(a, len);
*/
bool is_sorted(const int *a, unsigned int len) {
    unsigned int i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant sorted(a, i);
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        if (i > 0) {
            //@ assert i-1 < len;
            if (a[i-1] > a[i]) {
                return false;
            }
        }
        i++;
    }
    return true;
}
