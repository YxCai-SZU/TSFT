#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result >= 0;
    ensures \result == 1 || \result == 0 || \result == 5 || \result == 6 || 
            \result == 2 || \result == 9 || \result == 5;
    assigns \nothing;
*/
int32_t func(uint32_t n) {
    int32_t result;
    
    //@ assert (1 <= (n) && (n) <= 100000);
    
    switch (n % 10) {
        case 2: case 4: case 5: case 7: case 9:
            result = 1;
            break;
        case 0: case 1: case 6: case 8:
            result = 0;
            break;
        case 3:
            result = 5;
            break;
        default:
            result = 2;
            break;
    }
    
    //@ assert result >= 0;
    //@ assert result == 1 || result == 0 || result == 5 || result == 6 || result == 2 || result == 9 || result == 5;
    
    return result;
}
