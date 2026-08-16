#include <stddef.h>

/*@
    requires \valid(nums + (0..len-1));
    requires len > 0;
    ensures (\exists integer i; 0 <= i < (len) && (nums)[i] == (\result));
    ensures len == len;
*/
int search(int* nums, size_t len) {
    size_t low;
    size_t high;
    size_t mid;

    low = 0;
    high = len - 1;

    /*@
        loop invariant 0 <= low <= high < len;
        loop invariant len == len;
        loop invariant \forall integer k; 0 <= k < len ==> nums[k] == nums[k];
        loop invariant len > 0;
        loop assigns low, high, mid;
        loop variant high - low;
    */
    while (low < high) {
        mid = low + (high - low) / 2;

        if (nums[low] <= nums[mid] && nums[mid] <= nums[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    //@ assert (\exists integer i; 0 <= i < (len) && (nums)[i] == (nums[low]));
    return nums[low];
}
