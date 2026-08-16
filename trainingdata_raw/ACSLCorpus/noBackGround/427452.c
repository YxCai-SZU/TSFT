#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= (b) && (b) <= 100);
    ensures \result >= -1;
    ensures \result < 1005000;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b) {
    uint32_t x = 0;
    uint32_t i = 0;
    
    /*@
        loop invariant 0 <= i <= 100000;
        loop invariant x < 100000;
        loop assigns x, i;
        loop variant 100000 - i;
    */
    while (i < 100000) {
        x = i;
        if (x >= a && x <= b) {
            //@ assert (((x) * 8) / 100) >= -1;
            //@ assert (((x) * 8) / 100) < 1005000;
            return (int32_t)((x * 8) / 100);
        }
        i += 1;
    }
    
    //@ assert -1 >= -1;
    //@ assert -1 < 1005000;
    return -1;
}
