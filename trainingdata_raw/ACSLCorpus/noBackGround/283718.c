#include <stdint.h>

/*@
    requires (1 <= (input) <= 23);
    ensures \result == (48 - (input));
    assigns \nothing;
*/
int32_t func(int32_t input)
{
    int32_t result;
    
    //@ assert 48 - input >= 0;
    //@ assert 48 - input <= 47;
    
    result = 48 - input;
    return result;
}
