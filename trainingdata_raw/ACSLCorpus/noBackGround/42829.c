#include <stdbool.h>
/*@
    requires \valid(arr + (0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \forall integer i; 0 <= i < len ==> \result >= arr[i];
    ensures \exists integer i; 0 <= i < len && \result == arr[i];
*/
int find_max(int *arr, int len) {
    int max_element;
    int i;
    
    max_element = arr[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant (\forall integer k; 0 <= k < (i) ==> (max_element) >= (arr)[k]);
        loop invariant (\exists integer k; 0 <= k < (i) && (max_element) == (arr)[k]);
        loop invariant \forall integer k; 0 <= k < i ==> ((arr)[(k)]) == arr[k];
        loop assigns max_element, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert \forall integer k; 0 <= k < i ==> max_element >= arr[k];
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
        i++;
    }
    return max_element;
}
