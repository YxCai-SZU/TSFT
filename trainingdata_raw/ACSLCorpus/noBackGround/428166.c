#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures \exists integer i; 0 <= i < len && \result == arr[i];
    ensures \forall integer i; 0 <= i < len ==> \result >= arr[i];
*/
int find_maximum(int *arr, size_t len) {
    int max;
    size_t i;
    
    max = arr[0];
    i = 1;
    
    /*@
        loop invariant i <= len;
        loop invariant \exists integer k; 0 <= k < i && max == arr[k];
        loop invariant \forall integer k; 0 <= k < i ==> max >= arr[k];
        loop assigns max, i;
        loop variant len - i;
    */
    while (i < len) {
        if (arr[i] > max) {
            max = arr[i];
        }
        i++;
    }
    
    return max;
}
