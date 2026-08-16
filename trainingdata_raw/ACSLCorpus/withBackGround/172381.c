#include <stdbool.h>
#include <stddef.h>

/*@ predicate distinct_elements(int *A, integer len) =
      \forall integer i, j; 0 <= i < j < len ==> A[i] != A[j];
*/

/*@ predicate all_even(int *A, integer len) =
      \forall integer k; 0 <= k < len ==> (A[k] & 1) == 0;
*/

/*@
  requires \valid_read(A + (0 .. len-1));
  requires distinct_elements(A, len);
  assigns \nothing;
  ensures \result <==> all_even(A, len);
*/
bool contains_all_evens(int *A, size_t len) {
    size_t i = 0;

    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer k; 0 <= k < i ==> (A[k] & 1) == 0;
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if ((A[i] & 1) != 0) {
            return false;
        }
        i = i + 1;
    }
    return true;
}
