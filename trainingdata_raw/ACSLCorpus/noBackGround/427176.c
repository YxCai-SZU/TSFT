#include <stdint.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t five_hundreds_num;
    uint32_t remaining_x;
    uint32_t five_num;
    uint32_t result;

    five_hundreds_num = x / 500;
    remaining_x = x % 500;
    five_num = remaining_x / 5;
    result = five_hundreds_num * 1000 + five_num * 5;

    //@ assert result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    return result;
}
