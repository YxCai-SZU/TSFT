#include <stdint.h>

/*@
    requires x <= 0xFFFFFFFF;
    ensures \result <= 1;
    ensures \result == 1 ==> ((x) == 0xFFFFFFFF);
    ensures \result == 0 ==> !((x) == 0xFFFFFFFF);
*/
uint32_t func(uint32_t x) {
    uint32_t result;
    
    result = 0;
    
    if (x == 0xFFFFFFFF) {
        result = 1;
    }
    
    //@ assert result <= 1;
    
    return result;
}
