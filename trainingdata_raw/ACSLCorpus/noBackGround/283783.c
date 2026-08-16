#include <stdbool.h>
#include <limits.h>

/*@
    requires \valid(arr + (0..len-1));
    requires len > 0;
    requires \forall integer i; 0 <= i < len ==> arr[i] > INT_MIN && arr[i] < INT_MAX;
    ensures \exists integer i; 0 <= i < len && arr[i] == \result;
    ensures \forall integer i; 0 <= i < len ==> \result >= arr[i];
*/
int find_maximum(int *arr, int len) {
    int max;
    int i;
    
    max = arr[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \exists integer j; 0 <= j < i && arr[j] == max;
        loop invariant \forall integer j; 0 <= j < i ==> max >= arr[j];
        loop invariant len > 0;
        loop assigns max, i;
    */
    while (i < len) {
        if (arr[i] > max) {
            max = arr[i];
        }
        i++;
    }
    
    return max;
}
