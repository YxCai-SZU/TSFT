#include <stdint.h>

/*@
    requires (1 <= (a) <= 3 && 1 <= (b) <= 3 && (a) != (b));
    ensures \result == (6 - (a) - (b));
    assigns \nothing;
*/
int32_t func(uint64_t a, uint64_t b)
{
    int32_t result;
    uint64_t answer;

    answer = 6 - a - b;
    result = (int32_t)answer;

    //@ assert result == 6 - (int32_t)a - (int32_t)b;

    return result;
}
