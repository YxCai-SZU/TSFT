#include <stdint.h>

/*@
    requires 1 <= input <= 32;
    ensures \result > 0;
    ensures \result <= 49;
    ensures (input == 1 || input == 2 || input == 3) ==> \result == 1;
    ensures (input >= 4 && input <= 12) ==> \result == 2;
    ensures (input >= 13 && input <= 24) ==> \result == 3;
    ensures (input >= 25 && input <= 32) ==> \result == 4;
*/
uint32_t func(uint32_t input)
{
    uint32_t result;
    //@ assert 1 <= input <= 32;
    
    if (input <= 3) {
        result = 1;
    } else if (input <= 12) {
        result = 2;
    } else if (input <= 24) {
        result = 3;
    } else {
        result = 4;
    }
    
    return result;
}
