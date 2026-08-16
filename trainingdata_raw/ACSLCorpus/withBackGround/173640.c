#include <stdbool.h>
/*@
    predicate is_max(integer max_val, int* arr, integer len, integer idx) =
        max_val == arr[0] || \exists integer k; 0 <= k < idx && max_val == arr[k];
    predicate ge_all(integer max_val, int* arr, integer len, integer idx) =
        \forall integer k; 0 <= k < idx ==> max_val >= arr[k];
*/

/*@
    requires \valid(arr + (0 .. len-1)) && len > 0;
    ensures \result >= arr[0];
    ensures \result == arr[0] || \exists integer i; 0 <= i < len && \result == arr[i];
    ensures \forall integer i; 0 <= i < len ==> \result >= arr[i];
*/
int find_max(int* arr, int len) {
    int max_element;
    int i;
    
    max_element = arr[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant max_element >= arr[0];
        loop invariant is_max(max_element, arr, len, i);
        loop invariant ge_all(max_element, arr, len, i);
        loop assigns max_element, i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
        i = i + 1;
    }
    return max_element;
}
