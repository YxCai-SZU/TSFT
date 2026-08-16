#include <stdbool.h>
#include <stddef.h>

/*@ predicate has_common_element(unsigned int *v1, unsigned int *v2, size_t len1, size_t len2) =
      \exists size_t i, j; 0 <= i < len1 && 0 <= j < len2 && v1[i] == v2[j];
*/

/*@ predicate is_first_common(unsigned int *v1, unsigned int *v2, size_t len1, size_t len2, size_t idx1, size_t idx2, unsigned int val) =
      idx1 < len1 && idx2 < len2 &&
      v1[idx1] == val && v2[idx2] == val &&
      (\forall size_t k; 0 <= k < idx1 ==> v1[k] != val) &&
      (\forall size_t k; 0 <= k < idx2 ==> v2[k] != val);
*/

/*@ predicate no_common_element(unsigned int *v1, unsigned int *v2, size_t len1, size_t len2) =
      \forall size_t i, j; 0 <= i < len1 && 0 <= j < len2 ==> v1[i] != v2[j];
*/

/*@
  requires \valid_read(v1 + (0..len1-1));
  requires \valid_read(v2 + (0..len2-1));
  requires len1 > 0;
  requires len2 > 0;
  assigns \nothing;
  ensures \result == 0 ==> no_common_element(v1, v2, len1, len2);
  ensures \result != 0 ==> \exists size_t i, j; is_first_common(v1, v2, len1, len2, i, j, *\result);
*/
unsigned int *first_common_element(unsigned int *v1, size_t len1,
                                   unsigned int *v2, size_t len2) {
    size_t i;
    size_t j;
    i = 0;

    /*@
      loop invariant 0 <= i <= len1;
      loop invariant \forall size_t ii, jj; 0 <= ii < i && 0 <= jj < len2 ==> v1[ii] != v2[jj];
      loop assigns i, j;
      loop variant len1 - i;
    */
    while (i < len1) {
        j = 0;

        /*@
          loop invariant 0 <= j <= len2;
          loop invariant \forall size_t jj; 0 <= jj < j ==> v1[i] != v2[jj];
          loop assigns j;
          loop variant len2 - j;
        */
        while (j < len2) {
            //@ assert 0 <= i < len1 && 0 <= j < len2;
            if (v1[i] == v2[j]) {
                //@ assert is_first_common(v1, v2, len1, len2, i, j, v1[i]);
                return &v1[i];
            }
            j++;
        }
        i++;
    }
    //@ assert no_common_element(v1, v2, len1, len2);
    return 0;
}
