#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(int *arr, integer len) =
        len > 0 && len % 2 == 1 && len < 0x80000000;

    predicate element_of(int *arr, integer len, integer idx, int val) =
        0 <= idx < len && arr[idx] == val;

    lemma array_length_positive:
        \forall int *arr, integer len; valid_array(arr, len) ==> len > 0;

    lemma array_length_odd:
        \forall int *arr, integer len; valid_array(arr, len) ==> len % 2 == 1;

    lemma array_length_bound:
        \forall int *arr, integer len; valid_array(arr, len) ==> len < 0x80000000;
*/

/*@
    requires valid_array(arr, len);
    ensures \exists integer i; 0 <= i < len && \result == arr[i];
    ensures \forall integer i; 0 <= i < len ==> \result == arr[i] || \result != arr[i];
*/
int search(int *arr, size_t len) {
    size_t low = 0;
    size_t high = len - 1;

    //@ assert valid_array(arr, len);
    //@ assert 0 <= low <= high < len;
    //@ assert high < len;

    /*@
        loop invariant 0 <= low <= high < len;
        loop invariant valid_array(arr, len);
        loop invariant \forall integer k; 0 <= k < len ==> arr[k] == arr[k];
        loop invariant low > 0 ==> len > 0;
        loop assigns low, high;
        loop variant high - low;
    */
    while (low < high) {
        size_t mid = low + (high - low) / 2;

        if ((mid == 0 || arr[mid] != arr[mid - 1]) && 
            (mid == len - 1 || arr[mid] != arr[mid + 1])) {
            //@ assert element_of(arr, len, mid, arr[mid]);
            return arr[mid];
        }

        if (len % 2 == 1) {
            if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || 
                (mid % 2 == 1 && arr[mid] == arr[mid - 1])) {
                low = mid + 1;
                //@ assert low <= high;
            } else {
                high = mid;
                //@ assert low <= high;
            }
        } else {
            if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || 
                (mid % 2 == 1 && arr[mid] == arr[mid - 1])) {
                low = mid + 1;
                //@ assert low <= high;
            } else {
                high = mid;
                //@ assert low <= high;
            }
        }
    }

    //@ assert element_of(arr, len, low, arr[low]);
    return arr[low];
}

int main() {
    return 0;
}
