#include <stddef.h>
#include <stdbool.h>

/*@
    requires len > 0;
    requires \valid_read(a + (0 .. len-1));
    assigns \nothing;
    ensures (\forall integer j; 0 <= j < (len) ==> (a)[j] >= (\result));
 */
int min_element(int *a, size_t len) {
    // Variable declarations at top of scope
    int min_val;
    size_t i;
    
    min_val = a[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant (\forall integer j; 0 <= j < (i) ==> (a)[j] >= (min_val));
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
