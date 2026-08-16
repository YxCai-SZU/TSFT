#include <stdbool.h>
/*@ predicate sorted(int *arr, integer len) =
      \forall integer i, j; 0 <= i < j < len ==> arr[i] <= arr[j];
*/

/*@ predicate is_max(int *arr, integer len, integer idx) =
      0 <= idx < len &&
      \forall integer i; 0 <= i < len ==> arr[i] <= arr[idx];
*/

/*@ lemma max_exists: 
      \forall int *arr, integer len; 
      sorted(arr, len) && len > 0 ==> \exists integer idx; is_max(arr, len, idx);
*/

/*@ requires \valid(arr+(0..len-1));
    requires len > 0;
    requires sorted(arr, len);
    ensures \exists integer i; 0 <= i < len && \result == arr[i];
    ensures \forall integer i; 0 <= i < len ==> arr[i] <= \result;
    assigns \nothing;
*/
int find_max(int *arr, int len) {
    int max_element;
    int i;
    
    max_element = arr[0];
    i = 1;
    
    /*@ loop invariant 1 <= i <= len;
        loop invariant \exists integer k; 0 <= k < i && max_element == arr[k];
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] <= max_element;
        loop assigns max_element, i;
        loop variant len - i;
    */
    while (i < len) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
        //@ assert \exists integer k; 0 <= k < i+1 && max_element == arr[k];
        //@ assert \forall integer k; 0 <= k < i+1 ==> arr[k] <= max_element;
        i++;
    }
    return max_element;
}
