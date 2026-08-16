#include <stdint.h>

/*@
    requires (1 <= (input) && (input) <= 23);
    ensures (0 <= (\result) && (\result) <= 48);
    ensures \result == 48 - input;
*/
int32_t func(int32_t input)
{
    int32_t result;
    //@ assert 48 - input >= 0 && 48 - input <= 48;
    result = 48 - input;
    return result;
}
