#include <stdbool.h>

/*@
    requires \valid(nums + (0..len-1));
    requires len > 0;
    ensures (\exists integer idx; 0 <= idx < (len) && (nums)[idx] == (\result));
    ensures (\forall integer idx; 0 <= idx < (len) ==> (\result) >= (nums)[idx]);
*/
int find_max(int *nums, int len) {
    int max;
    int i;
    
    max = nums[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant (\exists integer idx; 0 <= idx < (i) && (nums)[idx] == (max));
        loop invariant (\forall integer idx; 0 <= idx < (i) ==> (max) >= (nums)[idx]);
        loop assigns max, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (nums[i] > max) {
            max = nums[i];
        }
        //@ assert (\exists integer idx; 0 <= idx < (i+1) && (nums)[idx] == (max));
        i = i + 1;
    }
    
    //@ assert i == len;
    //@ assert (\exists integer idx; 0 <= idx < (len) && (nums)[idx] == (max));
    return max;
}
