#include <stddef.h>
#include <limits.h>

/*@ predicate element_in_range(int* arr, integer len) =
      \forall integer i; 0 <= i < len ==> INT_MIN <= arr[i] <= INT_MAX;
*/

/*@ predicate max_is_element(int* arr, integer len, integer max_val) =
      \exists integer i; 0 <= i < len && max_val == arr[i];
*/

/*@ predicate max_ge_all(int* arr, integer len, integer max_val) =
      \forall integer i; 0 <= i < len ==> max_val >= arr[i];
*/

/*@ lemma max_preservation:
      \forall int* arr, integer len, integer i, integer max_val;
      element_in_range(arr, len) && len > 0 && 0 <= i < len &&
      max_is_element(arr, i, max_val) && max_ge_all(arr, i, max_val) &&
      arr[i] > max_val ==> max_is_element(arr, i+1, arr[i]) && max_ge_all(arr, i+1, arr[i]);
*/

/*@ lemma max_non_increase:
      \forall int* arr, integer len, integer i, integer max_val;
      element_in_range(arr, len) && len > 0 && 0 <= i < len &&
      max_is_element(arr, i, max_val) && max_ge_all(arr, i, max_val) &&
      arr[i] <= max_val ==> max_is_element(arr, i+1, max_val) && max_ge_all(arr, i+1, max_val);
*/

/*@ requires len > 0;
    requires \valid(arr + (0 .. len-1));
    requires element_in_range(arr, len);
    assigns \nothing;
    ensures max_is_element(arr, len, \result);
    ensures max_ge_all(arr, len, \result);
*/
int find_max(int* arr, size_t len) {
    int max_element;
    size_t i;
    
    max_element = arr[0];
    i = 1;
    
    /*@ loop invariant 1 <= i <= len;
        loop invariant max_is_element(arr, i, max_element);
        loop invariant max_ge_all(arr, i, max_element);
        loop invariant element_in_range(arr, len);
        loop assigns max_element, i;
        loop variant len - i;
    */
    while (i < len) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
        i++;
    }
    
    return max_element;
}
