#include <stdbool.h>

/*@ requires \valid(nums + (0..len-1));
    requires len >= 1;
    requires (\forall integer i; 0 <= i < (len) - 1 ==> (nums)[i] <= (nums)[i + 1] || (nums)[i] >= (nums)[i + 1]);
    ensures (\exists integer i; 0 <= i < (len) && (nums)[i] == (\result));
    assigns \nothing;
*/
int search(int* nums, int len) {
    int low;
    int high;
    int mid;
    
    low = 0;
    high = len - 1;
    
    /*@ loop invariant 0 <= low <= high < len;
        loop invariant (\forall integer i; 0 <= i < (len) - 1 ==> (nums)[i] <= (nums)[i + 1] || (nums)[i] >= (nums)[i + 1]);
        loop assigns low, high, mid;
        loop variant high - low;
    */
    while (low < high) {
        mid = low + (high - low) / 2;
        
        //@ assert 0 <= mid < len;
        
        if (nums[mid] < nums[high]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    //@ assert 0 <= low < len;
    
    int index = (low == 0) ? 0 : (low - 1);
    
    //@ assert 0 <= index < len;
    //@ assert (\exists integer i; 0 <= i < (len) && (nums)[i] == (nums[index]));
    
    return nums[index];
}
