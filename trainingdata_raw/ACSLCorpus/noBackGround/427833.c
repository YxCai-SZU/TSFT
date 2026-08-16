#include <stddef.h>
/*@
    requires ((s_len) >= 1 && (s_len) <= 10000 &&
        \forall integer i; 0 <= i < (s_len) ==> (s)[i] >= 1 && (s)[i] <= 10000);
    ensures \result >= 1 && \result <= s_len;
    assigns \nothing;
*/
size_t find_first_strictly_increasing_length_of_length_bounds(int *s, size_t s_len) {
    size_t length = 1;
    size_t i = 0;
    
    /*@
        loop invariant (0 <= (i) <= (s_len) - 1 &&
        (length) >= 1 &&
        (length) <= (i) + 1 &&
        \forall integer k; 0 <= k < (s_len) ==> (s)[k] >= 1 && (s)[k] <= 10000);
        loop assigns i, length;
        loop variant s_len - i;
    */
    while (i < s_len - 1) {
        //@ assert i >= 0 && i <= s_len - 1;
        
        if (s[i] < s[i + 1]) {
            length += 1;
        } else {
            break;
        }
        i += 1;
    }
    
    //@ assert length >= 1;
    //@ assert length <= s_len;
    return length;
}
