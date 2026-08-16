#include <stdbool.h>
/*@
    requires \valid(arr + (0 .. len-1));
    requires len > 0;
    ensures (\exists integer i; 0 <= i < (len) && (arr)[i] == (\result));
    assigns \nothing;
*/
int find_max_in_rotated_array(int *arr, int len) {
    int low = 0;
    int high = len - 1;

    /*@
        loop invariant 0 <= low <= high < len;
        loop invariant \forall integer i; 0 <= i < len ==> (\exists integer i; 0 <= i < (len) && (arr)[i] == (arr[i]));
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

    //@ assert (\exists integer i; 0 <= i < (len) && (arr)[i] == (arr[high]));
    return arr[high];
}
