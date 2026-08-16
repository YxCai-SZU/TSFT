#include <stdbool.h>
#include <limits.h>

/*@ requires \valid(arr) && len > 0;
    requires (\forall integer k; 0 <= k < (len) ==> INT_MIN <= (arr)[k] <= INT_MAX);
    ensures \exists integer i; 0 <= i < len && \result == arr[i];
    ensures (\forall integer j; 0 <= j < (len) ==> (arr)[j] <= (\result));
    assigns \nothing;
*/
int find_maximum(int* arr, int len) {
    int max = arr[0];
    int i = 1;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant \exists integer j; 0 <= j < i && max == arr[j];
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= max;
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
