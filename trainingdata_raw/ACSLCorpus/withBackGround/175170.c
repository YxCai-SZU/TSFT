#include <stddef.h>
#include <stdbool.h>

/*@
    predicate count_condition(int *arr, integer len, int threshold, integer i, integer cnt) =
        \forall integer j; 0 <= j < i ==> (arr[j] > threshold ==> cnt > 0);

    predicate count_identity(int *arr, integer len, int threshold, integer i, integer cnt) =
        \forall integer j; 0 <= j < i && arr[j] <= threshold ==> cnt == i - (i - cnt);

    logic integer total_length(integer len) = len;
*/

/*@
    requires \valid(nums + (0..len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len && nums[i] > threshold ==> \result > 0;
    ensures \forall integer i; 0 <= i < len && nums[i] <= threshold ==> \result == len - (len - \result);
*/
size_t count_greater_than(int *nums, size_t len, int threshold)
{
    size_t count = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant count <= i;
        loop invariant count_condition(nums, len, threshold, i, count);
        loop invariant count_identity(nums, len, threshold, i, count);
        loop invariant len < 0x80000000;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len)
    {
        //@ assert 0 <= i < len;
        if (nums[i] > threshold)
        {
            //@ assert nums[i] > threshold;
            count = count + 1;
        }
        //@ assert count_condition(nums, len, threshold, i+1, count);
        //@ assert count_identity(nums, len, threshold, i+1, count);
        i = i + 1;
    }
    //@ assert i == len;
    //@ assert \forall integer j; 0 <= j < len ==> (nums[j] > threshold ==> count > 0);
    return count;
}
