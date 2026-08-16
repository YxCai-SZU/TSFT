#include <stdbool.h>
#include <stddef.h>

/*@ requires ((len) >= 1 && (len) <= 200000 &&
    \forall integer i; 0 <= i < (len) ==> (v)[i] >= 1 && (v)[i] <= 1000000000);
    ensures \result >= 0 && \result <= len;
    assigns \nothing;
*/
int func(int *v, size_t len) {
    int c = 0;
    int x = 0;
    size_t i = 0;
    
    /*@ loop invariant (0 <= (i) <= (len) &&
    (c) >= -(int)(i) && (c) <= (int)(i) &&
    \forall integer k; 0 <= k < (i) ==> (v)[k] >= 1 && (v)[k] <= 1000000000);
        loop assigns c, i, x;
        loop variant len - i;
    */
    while (i < len) {
        x = v[i];
        //@ assert x >= 1 && x <= 1000000000;
        
        if (x >= 0) {
            c += 1;
        } else {
            //@ assert c >= 1;
            c -= 1;
        }
        i += 1;
    }
    
    int ans = (c < 0) ? -c : c;
    //@ assert ans >= 0 && ans <= len;
    return ans;
}
