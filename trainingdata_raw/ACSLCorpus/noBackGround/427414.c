#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid(nums + (0..len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len ==> 
            ((((nums[i]) & 1) != 0) ==> (\exists integer j; (0) <= j < (len) && ((((nums)[j]) & 1) != 0)));
*/
int filter_even(int *nums, size_t len) {
    int odd_count = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant odd_count >= 0;
        loop invariant odd_count <= i;
        loop invariant \forall integer k; 0 <= k < i ==> 
                      ((((nums[k]) & 1) != 0) ==> (\exists integer j; (0) <= j < (len) && ((((nums)[j]) & 1) != 0)));
        loop invariant len < 0x80000000;
        loop assigns odd_count, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert i < len;
        if ((nums[i] & 1) != 0) {
            odd_count += 1;
        }
        i += 1;
    }
    //@ assert i == len;
    //@ assert odd_count >= 0;
    //@ assert odd_count <= len;
    return odd_count;
}
