#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (1000 * ((x) / 500) + 5 * (((x) % 500) / 5));
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t result = 0;
    uint32_t temp_x = x;

    //@ assert temp_x == x;
    //@ assert result == 0;

    if (temp_x >= 500)
    {
        //@ assert temp_x / 500 == x / 500;
        result += 1000 * (temp_x / 500);
        temp_x = temp_x % 500;
        //@ assert temp_x == x % 500;
    }

    //@ assert temp_x == x % 500;

    if (temp_x >= 5)
    {
        //@ assert temp_x / 5 == (x % 500) / 5;
        result += 5 * (temp_x / 5);
    }

    //@ assert result == 1000 * (x / 500) + 5 * ((x % 500) / 5);
    //@ assert result == (1000 * ((x) / 500) + 5 * (((x) % 500) / 5));

    return result;
}
