#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    ensures \exists integer i; 0 <= i < len && \result == arr[i];
    ensures \forall integer j; 0 <= j < len ==> \result >= arr[j];
*/
int find_max(int *arr, size_t len) {
    int max_element;
    size_t i;
    
    max_element = arr[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \exists integer k; 0 <= k < i && max_element == arr[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_element >= arr[j];
        loop invariant len > 0;
        loop assigns max_element, i;
        loop variant len - i;
    */
    while (i < len) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
        i++;
    }
    
    //@ assert \exists integer i; 0 <= i < len && max_element == arr[i];
    //@ assert \forall integer j; 0 <= j < len ==> max_element >= arr[j];
    
    return max_element;
}
