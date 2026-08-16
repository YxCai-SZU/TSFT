#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

/*@
    requires x <= 8 && y <= 8 && z <= 8;
    ensures \result == 0 ==> !((x) <= 8 && (y) <= 8 && (z) <= 8 &&
        (uint64_t)(x) * (y) + (z) <= UINT32_MAX);
    ensures \result != 0 ==> *\result == x * y + z && ((x) <= 8 && (y) <= 8 && (z) <= 8 &&
        (uint64_t)(x) * (y) + (z) <= UINT32_MAX);
    assigns \result, \result[0..0];
*/
uint32_t* func(uint32_t x, uint32_t y, uint32_t z) {
    uint32_t* result;
    uint64_t product;
    uint64_t sum;
    
    result = 0;
    product = (uint64_t)x * y;
    sum = product + z;
    
    //@ assert product <= 64;
    //@ assert sum <= 72;
    
    if (product > UINT32_MAX - z) {
        //@ assert !((x) <= 8 && (y) <= 8 && (z) <= 8 &&         (uint64_t)(x) * (y) + (z) <= UINT32_MAX);
        return result;
    } else {
        //@ assert ((x) <= 8 && (y) <= 8 && (z) <= 8 &&         (uint64_t)(x) * (y) + (z) <= UINT32_MAX);
        static uint32_t value;
        value = (uint32_t)(x * y + z);
        result = &value;
        return result;
    }
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
