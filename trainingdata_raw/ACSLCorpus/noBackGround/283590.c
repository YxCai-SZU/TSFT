#include <stdint.h>

/*@
    requires (0 <= (a) <= 100 &&
        2 <= (b) <= 1000 &&
        (b) % 2 == 0);
    ensures \result >= 0;
    ensures \result <= b;
    ensures a >= 13 ==> \result == b;
    ensures 6 <= a < 13 ==> \result == b / 2;
    ensures a <= 5 ==> \result == 0;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;
    
    //@ assert (0 <= (a) <= 100 &&         2 <= (b) <= 1000 &&         (b) % 2 == 0);
    
    if (a >= 13) {
        result = b;
        //@ assert result == b;
    } else if (a >= 6) {
        result = b / 2;
        //@ assert result == b / 2;
    } else {
        result = 0;
        //@ assert result == 0;
    }
    
    //@ assert result >= 0;
    //@ assert result <= b;
    return result;
}
