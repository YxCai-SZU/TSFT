#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid(nums + (0..len-1));
    requires len > 0;
    requires (\forall integer i, j; 0 <= i < j < (len) ==> (nums)[i] != (nums)[j]);
    ensures (\exists integer i; 0 <= i < (len) && (nums)[i] == (\result)) || \result == -1;
*/
int search(int* nums, size_t len) {
    size_t low;
    size_t high;
    size_t mid;
    int result;
    
    low = 0;
    high = len - 1;
    
    /*@ loop invariant 0 <= low <= high < len;
        loop invariant (\forall integer i, j; 0 <= i < j < (len) ==> (nums)[i] != (nums)[j]);
        loop invariant len > 0;
        loop assigns low, high;
        loop variant high - low;
    */
    while (low < high) {
        mid = low + (high - low) / 2;
        
        //@ assert mid >= low && mid <= high;
        
        if ((mid == 0 || nums[mid] != nums[mid - 1]) && 
            (mid == len - 1 || nums[mid] != nums[mid + 1])) {
            return nums[mid];
        }
        
        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || 
            (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    //@ assert low == high;
    
    if (low < len && 
        (low == 0 || nums[low] != nums[low - 1]) && 
        (low == len - 1 || nums[low] != nums[low + 1])) {
        result = nums[low];
    } else {
        result = -1;
    }
    
    //@ assert (\exists integer i; 0 <= i < (len) && (nums)[i] == (result)) || result == -1;
    return result;
}
