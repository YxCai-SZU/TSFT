#include <stdbool.h>
#include <stdint.h>

/*@ requires n > 0 && n <= 100;
    requires \valid(v + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((v)[i]) <= 100));
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
uint32_t func(uint32_t n, int32_t *v) {
    uint32_t r = 0;
    uint32_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant r >= 0;
        loop invariant r <= i;
        loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((v)[i]) <= 100));
        loop assigns r, i;
    */
    while (i < n) {
        int32_t v_i = v[i];
        //@ assert (1 <= (v_i) <= 100);
        
        if (v_i & 1) {
            r = r + 1;
        }
        
        i = i + 1;
    }
    
    return r;
}
