#include <stdbool.h>

/*@
    predicate exists_max(int *arr, integer len, integer max_val, integer idx) =
        0 <= idx < len && arr[idx] == max_val;

    predicate forall_max(int *arr, integer len, integer max_val, integer i) =
        \forall integer j; 0 <= j < i ==> max_val >= arr[j];

    lemma max_preservation:
        \forall int *arr, integer len, integer i, integer max_val;
            (0 <= i < len && forall_max(arr, len, max_val, i) && arr[i] > max_val) ==>
            forall_max(arr, len, arr[i], i+1);
*/

/*@
    requires \valid(nums + (0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \exists integer i; 0 <= i < len && \result == nums[i];
    ensures \forall integer i; 0 <= i < len ==> \result >= nums[i];
*/
int find_max_num(int *nums, int len) {
    int max_num;
    int i;
    
    max_num = nums[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \exists integer j; 0 <= j < i && max_num == nums[j];
        loop invariant \forall integer j; 0 <= j < i ==> max_num >= nums[j];
        loop assigns max_num, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert \forall integer j; 0 <= j < i ==> max_num >= nums[j];
        if (nums[i] > max_num) {
            max_num = nums[i];
        }
        //@ assert \exists integer j; 0 <= j < i+1 && max_num == nums[j];
        i++;
    }
    return max_num;
}
