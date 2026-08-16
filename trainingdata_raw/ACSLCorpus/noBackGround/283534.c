#include <stdbool.h>

/*@
    requires len > 0;
    requires \valid(nums + (0 .. len-1));
    ensures \forall integer k; 0 <= k < len ==> \result >= nums[k];
    ensures \exists integer k; 0 <= k < len && \result == nums[k];
    assigns \nothing;
*/
int find_max_num(int* nums, int len)
{
    int max_num;
    int i;
    
    //@ assert len > 0;
    max_num = nums[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer k; 0 <= k < i ==> max_num >= nums[k];
        loop invariant \exists integer k; 0 <= k < i && max_num == nums[k];
        loop assigns max_num, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (nums[i] > max_num) {
            max_num = nums[i];
        }
        i = i + 1;
    }
    //@ assert i == len;
    //@ assert \forall integer k; 0 <= k < len ==> max_num >= nums[k];
    //@ assert \exists integer k; 0 <= k < len && max_num == nums[k];
    return max_num;
}
