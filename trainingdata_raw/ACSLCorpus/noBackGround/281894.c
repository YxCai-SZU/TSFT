#include <stdbool.h>
/*@
    requires ((len) > 0 &&
        \forall integer i; 0 <= i < (len) ==> \valid((arr) + i));
    ensures (\exists integer j; 0 <= j < (len) && (arr)[j] == (\result));
    assigns \nothing;
*/
int find_max_in_rotated_array(int *arr, int len) {
    int low = 0;
    int high = len - 1;

    /*@
        loop invariant 0 <= low <= high < len;
        loop invariant low <= high + 1;
        loop invariant high < len;
        loop invariant len > 0;
        loop invariant \forall integer k; 0 <= k < len ==> arr[k] == \at(arr[k], Pre);
        loop invariant ((len) > 0 &&
        \forall integer i; 0 <= i < (len) ==> \valid((arr) + i));
        loop assigns low, high;
        loop variant high - low;
    */
    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    //@ assert (\exists integer j; 0 <= j < (len) && (arr)[j] == (arr[high]));
    return arr[high];
}
