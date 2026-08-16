#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(nums + (0..len-1));
    ensures \result == true ==> \exists integer i; ((0 <= (i) < (len)) && ((nums)[(i)] == (target)));
    ensures \result == false ==> \forall integer i; 0 <= i < len ==> nums[i] != target;
*/
bool contains_num(int *nums, size_t len, int target) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> nums[j] != target;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert (\forall integer j; (0 <= j < (i)) ==> ((nums)[j] != (target)));
        if (nums[i] == target) {
            //@ assert ((0 <= (i) < (len)) && ((nums)[(i)] == (target)));
            return true;
        }
        i++;
    }
    return false;
}
