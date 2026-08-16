#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        (a) + (b) >= 2);
    ensures \result >= 0;
    ensures \result <= a + b;
    ensures (a + b) % 2 == 0 ==> \result == (a + b) / 2;
    ensures (a + b) % 2 == 1 ==> \result == (a + b) / 2 + 1;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t result;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100 &&         (a) + (b) >= 2);
    sum = a + b;
    result = sum / 2;

    if (sum % 2 == 1)
    {
        result += 1;
        //@ assert result == (a + b) / 2 + 1;
    }
    else
    {
        //@ assert result == (a + b) / 2;
    }

    //@ assert result >= 0;
    return result;
}
