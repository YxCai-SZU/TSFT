#include <stdbool.h>
#include <stddef.h>

/*@ requires len > 0;
    requires \valid(nums + (0 .. len-1));
    assigns \nothing;
    ensures (\exists integer idx; 0 <= idx < (len) && (nums)[idx] == (\result));
*/
int find_min(int *nums, size_t len) {
    int min_val = nums[0];
    size_t i = 1;
    
    /*@ loop invariant 1 <= i <= len;
        loop invariant (\exists integer idx; 0 <= idx < (i) && (nums)[idx] == (min_val));
        loop assigns min_val, i;
        loop variant len - i;
    */
    while (i < len) {
        int num = nums[i];
        if (num < min_val) {
            min_val = num;
        }
        i++;
    }
    //@ assert (\exists integer idx; 0 <= idx < (len) && (nums)[idx] == (min_val));
    return min_val;
}
