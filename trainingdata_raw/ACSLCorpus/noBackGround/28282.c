#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((len) >= 0 && (len) < 0x80000000 &&
        \valid((nums1) + (0 .. (len)-1)) &&
        \valid((nums2) + (0 .. (len)-1)));
    ensures \result >= 0;
    ensures \result <= len;
*/
int count_greater_than(int *nums1, int *nums2, int len) {
    int count = 0;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant count >= 0;
        loop invariant count <= i;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert i >= 0 && i < len;
        
        if (nums1[i] > nums2[i]) {
            count += 1;
        }
        
        i += 1;
    }
    
    return count;
}
