#include <stdint.h>

/*@
    requires (0 <= (x) && (x) < 128 &&
        0 <= (y) && (y) < 128 &&
        2 * (x) + (y) < 256);
    ensures \result == (2 * (x) + (y));
    assigns \nothing;
*/
uint8_t double_and_sum(uint8_t x, uint8_t y)
{
    //@ assert (0 <= (x) && (x) < 128 &&         0 <= (y) && (y) < 128 &&         2 * (x) + (y) < 256);
    uint8_t result = 2 * x + y;
    //@ assert result == (2 * (x) + (y));
    return result;
}

int main()
{
    uint8_t x = 40;
    uint8_t y = 10;
    uint8_t result = double_and_sum(x, y);
    //@ assert result == 90;
    return 0;
}
