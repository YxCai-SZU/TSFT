/*@
    predicate element_exists(int *arr, integer len, integer idx, integer val) =
        0 <= idx < len && arr[idx] == val;

    predicate is_max_in_range(int *arr, integer len, integer end, integer max_val) =
        \forall integer j; 0 <= j < end ==> max_val >= arr[j];

    lemma max_exists_in_full_array:
        \forall int *arr, integer len, integer max_val;
        element_exists(arr, len, len, max_val) && is_max_in_range(arr, len, len, max_val) ==>
        (\exists integer i; 0 <= i < len && arr[i] == max_val) &&
        (\forall integer i; 0 <= i < len ==> max_val >= arr[i]);
*/

#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    requires len < 0x80000000;
    ensures \exists integer i; 0 <= i < len && \result == arr[i];
    ensures \forall integer i; 0 <= i < len ==> \result >= arr[i];
    assigns \nothing;
*/
int find_max(const int *arr, size_t len) {
    int max_element;
    size_t i;

    max_element = arr[0];
    i = 1;

    /*@
        loop invariant i <= len;
        loop invariant \exists integer j; 0 <= j < i && max_element == arr[j];
        loop invariant \forall integer j; 0 <= j < i ==> max_element >= arr[j];
        loop assigns max_element, i;
        loop variant len - i;
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
