#include <stdbool.h>

/*@
    predicate element_exists{L}(int *arr, integer len, integer idx, integer val) =
        0 <= idx < len && \at(arr[idx], L) == val;

    predicate all_ge{L}(int *arr, integer len, integer bound, integer val) =
        \forall integer j; 0 <= j < bound ==> \at(arr[j], L) >= val;

    logic integer min_val_spec{L}(int *arr, integer len, integer i, integer minv) =
        i == 0 ? \at(arr[0], L) :
        \at(arr[i], L) < minv ? \at(arr[i], L) : minv;

    lemma min_val_exists:
        \forall int *arr, integer len, integer i, integer minv;
        0 <= i < len && element_exists(arr, len, i, minv) ==>
        element_exists(arr, len, i, min_val_spec(arr, len, i, minv));
*/

/*@
    requires \valid(arr + (0 .. len-1));
    requires len > 0;
    ensures \exists integer i; 0 <= i < len && arr[i] == \result;
    ensures \forall integer j; 0 <= j < len ==> arr[j] >= \result;
*/
int min_element(int *arr, int len) {
    int min_val;
    int i;
    
    min_val = arr[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \exists integer k; 0 <= k < i && arr[k] == min_val;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] >= min_val;
        loop assigns i, min_val;
        loop variant len - i;
    */
    for (; i < len; ++i) {
        //@ assert \valid(arr + (0 .. len-1));
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    return min_val;
}
