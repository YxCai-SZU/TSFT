#include <stddef.h>
#include <stdbool.h>

/*@
    requires \valid(nums + (0..len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures 0 <= \result <= len;
    ensures \forall integer i; 0 <= i < len && nums[i] == 0 ==> \result > 0;
    ensures \forall integer i; 0 <= i < len && nums[i] != 0 ==> \result <= len;
*/
size_t count_zeros(int *nums, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < i && nums[j] == 0 ==> count > 0;
        loop invariant \forall integer j; 0 <= j < i && nums[j] != 0 ==> count <= i;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        int x = nums[i];
        if (x == 0) {
            count++;
        }
        i++;
    }
    
    return count;
}
