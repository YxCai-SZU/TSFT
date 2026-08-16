#include <stdint.h>

/*@ requires (0 <= (a) && (a) <= 100) && (0 <= (b) && (b) <= 100);
    ensures \result == ((((a)) * ((b))) / 100);
    assigns \nothing;
 */
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t complex_calculation;
    uint32_t result;
    
    //@ assert (0 <= (a) && (a) <= 100) && (0 <= (b) && (b) <= 100);
    //@ assert ((a) * (b)) <= 10000;
    
    complex_calculation = a * b;
    result = complex_calculation / 100;
    
    //@ assert result == ((((a)) * ((b))) / 100);
    return result;
}
