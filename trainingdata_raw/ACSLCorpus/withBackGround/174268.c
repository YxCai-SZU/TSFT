#include <stddef.h>
#include <stdbool.h>

/*@ predicate count_nonzero_invariant(size_t i, size_t count, size_t len, int *nums) =
        i <= len &&
        count <= i &&
        (\forall size_t j; 0 <= j < i ==> (nums[j] != 0 ==> count > 0));
*/

/*@ lemma count_nonzero_lemma:
        \forall size_t i, size_t count, size_t len, int *nums;
        count_nonzero_invariant(i, count, len, nums) ==>
        count <= len && count >= 0;
*/

/*@
    requires \valid(nums + (0..len-1));
    requires len <= 0x80000000;
    assigns \nothing;
    ensures \result <= len;
    ensures \result >= 0;
    ensures \forall size_t i; 0 <= i < len ==> (nums[i] != 0 ==> \result > 0);
*/
size_t count_nonzero(int *nums, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant count <= i;
        loop invariant \forall size_t j; 0 <= j < i ==> (nums[j] != 0 ==> count > 0);
        loop invariant len <= 0x80000000;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert count_nonzero_invariant(i, count, len, nums);
        if (nums[i] != 0) {
            count += 1;
        }
        i += 1;
    }
    //@ assert count_nonzero_invariant(i, count, len, nums);
    return count;
}
