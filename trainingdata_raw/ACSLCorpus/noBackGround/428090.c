#include <stdbool.h>
/*@
    requires \valid_read(arr + (0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \exists integer i; 0 <= i < len && \result == arr[i];
    ensures \forall integer j; 0 <= j < len ==> \result >= arr[j];
*/
int find_max(const int* arr, int len) {
    int max_element;
    int i;
    
    max_element = arr[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \exists integer j; 0 <= j < i && max_element == arr[j];
        loop invariant \forall integer j; 0 <= j < i ==> max_element >= arr[j];
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
