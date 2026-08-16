#include <stdbool.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures \exists integer i; 0 <= i < len && \result == arr[i];
    ensures \forall integer j; 0 <= j < len ==> \result >= arr[j];
*/
int max_in_list(int *arr, int len) {
    int max;
    int i;
    max = arr[0];
    i = 1;
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \exists integer j; 0 <= j < i && max == arr[j];
        loop invariant \forall integer k; 0 <= k < i ==> max >= arr[k];
        loop assigns max, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert \forall integer k; 0 <= k < i ==> max >= arr[k];
        if (arr[i] > max) {
            max = arr[i];
        }
        i = i + 1;
    }
    return max;
}
