#include <stdbool.h>

/*@ predicate valid_range(int *arr, integer len) =
      len == 3 &&
      \forall integer i; 0 <= i < len ==> 1 <= arr[i] && arr[i] <= 100;
*/

/*@ logic integer element_at(int *arr, integer i) = arr[i]; */

/*@ lemma diff_bounds:
      \forall int *arr; valid_range(arr, 3) ==>
        element_at(arr, 1) - element_at(arr, 0) >= -99 &&
        element_at(arr, 1) - element_at(arr, 0) <= 99;
*/

/*@ lemma diff_bounds2:
      \forall int *arr; valid_range(arr, 3) ==>
        element_at(arr, 2) - element_at(arr, 1) >= -99 &&
        element_at(arr, 2) - element_at(arr, 1) <= 99;
*/


bool func(int *s) {
    int n0;
    int n1;
    int n2;
    int diff1;
    int diff2;
    bool result;

    n0 = s[0];
    n1 = s[1];
    n2 = s[2];

    //@ assert n1 - n0 >= -99 && n1 - n0 <= 99;
    //@ assert n2 - n1 >= -99 && n2 - n1 <= 99;

    diff1 = n1 - n0;
    diff2 = n2 - n1;
    result = (diff1 == diff2);
    return result;
}
