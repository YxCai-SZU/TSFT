#include <stdbool.h>
#include <stddef.h>

/*@ predicate element_in_range{L}(int *arr, integer len, integer idx, int val) =
     0 <= idx < len && arr[idx] == val;
*/

/*@ predicate min_element_in_prefix{L}(int *arr, integer len, integer i, int min) =
     \exists integer j; 0 <= j < i && arr[j] == min;
*/

/*@ lemma min_remains_in_prefix:
      \forall int *arr, integer len, integer i, int min;
      min_element_in_prefix(arr, len, i, min) ==>
      (i < len && arr[i] >= min ==> min_element_in_prefix(arr, len, i+1, min));
*/

/*@ lemma min_updated_in_prefix:
      \forall int *arr, integer len, integer i, int old_min;
      min_element_in_prefix(arr, len, i, old_min) ==>
      (i < len && arr[i] < old_min ==> min_element_in_prefix(arr, len, i+1, arr[i]));
*/

/*@ requires len > 0;
    requires \valid(arr + (0 .. len-1));
    assigns \nothing;
    ensures \exists integer j; 0 <= j < len && arr[j] == \result;
    ensures \forall integer k; 0 <= k < len ==> arr[k] >= \result;
*/
int find_min_element(int *arr, size_t len) {
    int min_element = arr[0];
    size_t i = 1;
    
    /*@ loop invariant 1 <= i <= len;
        loop invariant min_element_in_prefix(arr, len, i, min_element);
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] >= min_element;
        loop assigns min_element, i;
        loop variant len - i;
    */
    while (i < len) {
        if (arr[i] < min_element) {
            min_element = arr[i];
        }
        i++;
    }
    //@ assert \forall integer k; 0 <= k < len ==> arr[k] >= min_element;
    return min_element;
}
