#include <stdbool.h>

/*@ requires \valid(nums+(0..len-1));
    requires len > 0;
    ensures \result >= nums[0];
    ensures len > 1 ==> \result >= nums[len-1];
    ensures (\forall integer k; 0 <= k < (len) ==> (nums)[k] <= (\result));
*/
int find_max(int* nums, int len) {
    int max_element;
    int i;
    
    max_element = nums[0];
    i = 1;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant (\forall integer k; 0 <= k < (i) ==> (nums)[k] <= (max_element));
        loop invariant len > 0;
        loop assigns max_element, i;
        loop variant len - i;
    */
    while (i < len) {
        if (nums[i] > max_element) {
            max_element = nums[i];
        }
        i = i + 1;
    }
    
    //@ assert (\forall integer k; 0 <= k < (len) ==> (nums)[k] <= (max_element));
    //@ assert nums[0] <= max_element;
    //@ assert len > 1 ==> nums[len-1] <= max_element;
    
    return max_element;
}
