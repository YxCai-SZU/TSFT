#include <stdint.h>

/*@
    requires (1 <= (input) && (input) <= 1000000000);
    ensures \result == (((input) - 1) / 2 + 1);
    ensures \result >= 1;
    ensures \result <= input;
*/
uint32_t func(uint32_t input) {
    uint32_t result;
    
    //@ assert input >= 1 && input <= 1000000000;
    
    result = (input - 1) / 2 + 1;
    
    //@ assert result == (((input) - 1) / 2 + 1);
    //@ assert result >= 1;
    //@ assert result <= input;
    
    return result;
}
