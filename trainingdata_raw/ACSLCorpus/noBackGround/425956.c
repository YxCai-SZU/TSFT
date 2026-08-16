#include <stdbool.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures \exists integer i; 0 <= i < len && \result == arr[i];
    ensures \forall integer i; 0 <= i < len ==> \result >= arr[i];
*/
int find_max(int *arr, int len) {
    int max_val;
    int i;
    max_val = arr[0];
    i = 1;
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \exists integer j; 0 <= j < i && max_val == arr[j];
        loop invariant \forall integer k; 0 <= k < i ==> max_val >= arr[k];
        loop assigns max_val, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        i = i + 1;
    }
    return max_val;
}
