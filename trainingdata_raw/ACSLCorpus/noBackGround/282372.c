#include <stdint.h>

/*@
  requires ((a) <= 0xFFFF) && ((b) <= 0xFFFF);
  ensures \result == ((a) + (b) + 1);
  assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    // Variable declarations at top of scope
    uint32_t sum;
    uint32_t result;
    
    // Since a and b are 16-bit integers, their sum will not overflow u32
    sum = a + b;
    
    // Proof block assertions
    //@ assert sum <= 0x1FFFE;
    
    // The postcondition requires that result be the increment of the sum
    result = sum + 1;
    
    // Postcondition
    //@ assert result == ((a) + (b) + 1);
    
    return result;
}
