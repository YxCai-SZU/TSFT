#include <stdint.h>
/*@
    requires ((4) == 4 &&
        \valid((x) + (0 .. (4)-1)) &&
        (x)[0] <= 1000000000 &&
        (x)[1] <= 1000000000 &&
        (x)[2] <= 1000000000 &&
        (x)[3] <= 1000000000);
    assigns \nothing;
    ensures \result <= ((x)[0] + (x)[1] + (x)[2] + (x)[3]);
    ensures \result == x[0] || \result == x[1] || \result == x[2] || \result == x[3];
*/
uint64_t func(uint64_t *x) {
    uint64_t max1;
    uint64_t max2;
    uint64_t ret;

    //@ assert ((4) == 4 &&         \valid((x) + (0 .. (4)-1)) &&         (x)[0] <= 1000000000 &&         (x)[1] <= 1000000000 &&         (x)[2] <= 1000000000 &&         (x)[3] <= 1000000000);
    
    if (x[0] > x[1]) {
        max1 = x[0];
    } else {
        max1 = x[1];
    }
    
    if (x[2] > x[3]) {
        max2 = x[2];
    } else {
        max2 = x[3];
    }
    
    //@ assert max1 <= x[0] + x[1];
    //@ assert max2 <= x[2] + x[3];
    
    if (max1 > max2) {
        ret = max1;
    } else {
        ret = max2;
    }
    
    return ret;
}
