#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures \result == ((a) <= (b) * 2 ? -1 : (a) - (b) * 2);
    ensures \result == -1 || (\result >= 0 && (uint32_t)\result == a - b * 2);
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t temp1;
    uint32_t temp2;
    int32_t result;

    temp1 = b * 2;
    if (a <= temp1)
    {
        result = -1;
        //@ assert result == ((a) <= (b) * 2 ? -1 : (a) - (b) * 2);
        return result;
    }

    //@ assert a > b * 2;
    temp2 = a - temp1;
    result = (int32_t)temp2;
    //@ assert result == ((a) <= (b) * 2 ? -1 : (a) - (b) * 2);
    return result;
}
