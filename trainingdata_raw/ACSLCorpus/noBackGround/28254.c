#include <stdbool.h>

/*@ requires \valid(nums + (0..len-1));
    requires len > 0;
    requires (\forall integer i, j; 0 <= i < j < (len) ==> (nums)[i] != (nums)[j]);
    ensures \exists integer i; 0 <= i < len && nums[i] == \result;
    ensures \forall integer j; 0 <= j < len ==> nums[j] >= \result;
*/
int min_unique(int *nums, int len) {
    int min;
    int index;
    
    min = nums[0];
    index = 1;
    
    /*@ loop invariant 0 <= index <= len;
        loop invariant (\exists integer i; 0 <= i < (index) && (nums)[i] == (min));
        loop invariant (\forall integer j; 0 <= j < (index) ==> (nums)[j] >= (min));
        loop invariant len > 0;
        loop invariant (\forall integer i, j; 0 <= i < j < (len) ==> (nums)[i] != (nums)[j]);
        loop assigns min, index;
    */
    while (index < len) {
        if (nums[index] < min) {
            min = nums[index];
        }
        index++;
    }
    
    return min;
}
