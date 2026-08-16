#include <stdint.h>

/*@ requires 0 <= a <= 100 && 0 <= b <= 100;
    ensures ((\result) == (a) + (b) || (\result) == (a) * (b));
    ensures ((\result) >= (a) + (b));
    ensures ((\result) >= (a) * (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t sum;
    uint32_t product;
    uint32_t result;

    sum = a + b;
    //@ assert a * b <= 10000;
    product = a * b;
    
    if (sum > product) {
        result = sum;
    } else {
        result = product;
    }
    
    //@ assert ((result) == (a) + (b) || (result) == (a) * (b));
    //@ assert ((result) >= (a) + (b));
    //@ assert ((result) >= (a) * (b));
    
    return result;
}
