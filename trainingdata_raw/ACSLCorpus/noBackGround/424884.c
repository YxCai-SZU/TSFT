#include <stdint.h>

/*@
    requires (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (c) <= 100);
    ensures \result <= ((a) + (b) + (c));
    ensures \result >= ((a) + (b)) || \result >= ((c) + (a)) || \result >= ((b) + (c));
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t max1;
    uint32_t max2;
    
    //@ assert ((a) + (b)) <= 200;
    //@ assert ((b) + (c)) <= 200;
    //@ assert ((c) + (a)) <= 200;
    
    if (a + b > b + c) {
        max1 = a + b;
    } else {
        max1 = b + c;
    }
    
    if (c + a > max1) {
        max2 = c + a;
    } else {
        max2 = max1;
    }
    
    return max2;
}
