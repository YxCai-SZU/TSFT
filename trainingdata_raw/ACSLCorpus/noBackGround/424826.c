#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= -1 && \result <= 1;
    ensures \result == 1 ==> ((a) * 10 / 9) < b;
    ensures \result == 0 ==> ((a) * 10 / 9) == b;
    ensures \result == -1 ==> ((a) * 10 / 9) > b;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Declare all variables at the top
    int32_t result;
    uint32_t scaled_value;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    //@ assert 1 <= a <= 100;
    //@ assert a * 10 <= 1000;
    //@ assert a * 10 / 9 <= 111;
    
    scaled_value = a * 10 / 9;
    
    if (scaled_value < b) {
        result = 1;
        //@ assert scaled_value < b;
    } else if (scaled_value == b) {
        result = 0;
        //@ assert scaled_value == b;
    } else {
        //@ assert scaled_value > b;
        result = -1;
    }
    
    //@ assert result >= -1 && result <= 1;
    return result;
}
