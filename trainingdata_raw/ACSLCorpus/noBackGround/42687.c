#include <stddef.h>

/*@ requires len > 0;
    requires \valid(a + (0 .. len-1));
    assigns \nothing;
    ensures \exists integer idx; 0 <= idx < len && a[idx] == \result;
    ensures \forall integer k; 0 <= k < len ==> \result <= a[k];
*/
int min_element(int* a, size_t len) {
    // Variable declarations at scope top
    int min_val;
    size_t i;
    
    min_val = a[0];
    i = 1;
    
    /*@ loop invariant 1 <= i <= len;
        loop invariant \exists integer k; 0 <= k < i && a[k] == min_val;
        loop invariant \forall integer k; 0 <= k < i ==> min_val <= a[k];
        loop assigns min_val, i;
        loop variant len - i;
    */
    while (i < len) {
        if (a[i] < min_val) {
            min_val = a[i];
        }
        i++;
    }
    
    return min_val;
}
