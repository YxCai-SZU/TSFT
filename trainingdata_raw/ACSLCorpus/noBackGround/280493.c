#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == ((a) <= ((b) * 2) ? 0 : ((a) - ((b) * 2) + 1));
    ensures \result >= 0;
    ensures \result == 0 || \result == (a - (b * 2) + 1);
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t b_times_2;
    int32_t result;

    b_times_2 = b * 2;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    //@ assert 1 <= a <= 100 && 1 <= b <= 100;

    if (a <= b_times_2)
    {
        //@ assert a <= b_times_2;
        result = 0;
    }
    else
    {
        //@ assert a > b_times_2;
        result = (int32_t)(a - b_times_2 + 1);
    }

    //@ assert result == ((a) <= ((b) * 2) ? 0 : ((a) - ((b) * 2) + 1));
    //@ assert result >= 0;
    //@ assert result == 0 || result == (a - (b * 2) + 1);
    return result;
}
