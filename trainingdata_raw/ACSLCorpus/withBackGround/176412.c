#include <stdbool.h>
#include <stddef.h>

/*@ predicate min_in_range(int *arr, integer len, integer i, integer min) =
       \forall integer k; 0 <= k < i ==> min <= arr[k];
*/

/*@ predicate min_exists(int *arr, integer len, integer i, integer min) =
       \exists integer k; 0 <= k < i && min == arr[k];
*/

/*@ lemma min_preservation:
       \forall int *arr, integer len, integer i, integer min;
       min_in_range(arr, len, i, min) && min_exists(arr, len, i, min) &&
       0 <= i < len && min <= arr[i] ==>
       min_in_range(arr, len, i+1, min) && min_exists(arr, len, i+1, min);
*/

/*@ lemma min_update:
       \forall int *arr, integer len, integer i, integer min;
       min_in_range(arr, len, i, min) && min_exists(arr, len, i, min) &&
       0 <= i < len && arr[i] < min ==>
       min_in_range(arr, len, i+1, arr[i]) && min_exists(arr, len, i+1, arr[i]);
*/

/*@ requires len > 0;
    requires \valid_read(nums + (0 .. len-1));
    ensures \result <= nums[0];
    ensures \result <= nums[len-1];
*/
int min_sub_array(int *nums, size_t len)
{
    int min;
    size_t i;
    
    min = nums[0];
    i = 1;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant min_in_range(nums, len, i, min);
        loop invariant min_exists(nums, len, i, min);
        loop assigns i, min;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert min_in_range(nums, len, i, min);
        
        if (nums[i] < min) {
            min = nums[i];
        }
        i++;
    }
    
    //@ assert min_in_range(nums, len, len, min);
    return min;
}
