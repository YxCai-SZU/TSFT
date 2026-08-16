#include <stdbool.h>

/*@ predicate has_duplicate(int *a, integer len) =
      \exists integer i, j; 0 <= i < j < len && a[i] == a[j];
*/

/*@ predicate no_duplicate_before(int *a, integer i) =
      \forall integer k, l; 0 <= k < l < i ==> a[k] != a[l];
*/

/*@ predicate no_match_before(int *a, integer i, integer j) =
      \forall integer k; 0 <= k < j ==> a[k] != a[i];
*/

/*@
  requires len > 0;
  requires \valid(a + (0 .. len-1));
  assigns \nothing;
  ensures \result == true <==> has_duplicate(a, len);
*/
bool test_duplicate(int *a, int len) {
    int i = 1;
    int j = 0;
    
    /*@
      loop invariant 1 <= i <= len;
      loop invariant no_duplicate_before(a, i);
      loop assigns i, j;
      loop variant len - i;
    */
    while (i < len) {
        j = 0;
        
        /*@
          loop invariant 0 <= j <= i;
          loop invariant no_match_before(a, i, j);
          loop assigns j;
          loop variant i - j;
        */
        while (j < i) {
            //@ assert 0 <= j < i < len;
            if (a[i] == a[j]) {
                //@ assert has_duplicate(a, len);
                return true;
            }
            j++;
        }
        i++;
    }
    //@ assert !has_duplicate(a, len);
    return false;
}
