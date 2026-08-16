#include <stddef.h>

/*@ requires \valid(arr + (0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \exists integer i; 0 <= i < len && arr[i] == \result;
    ensures \forall integer j; 0 <= j < len ==> arr[j] <= \result;
*/
int max_element(int *arr, size_t len) {
    int max_val;
    size_t i;
    
    max_val = arr[0];
    i = 1;
    
    /*@ loop invariant 1 <= i <= len;
        loop invariant len > 0;
        loop invariant \exists integer k; 0 <= k < i && arr[k] == max_val;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= max_val;
        loop invariant \forall integer k; 0 <= k < len ==> arr[k] == arr[k];
        loop assigns max_val, i;
        loop variant len - i;
    */
    while (i < len) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        i++;
    }
    
    return max_val;
}
