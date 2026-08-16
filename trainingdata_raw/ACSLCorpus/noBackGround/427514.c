#include <stdint.h>

/*@ requires ((x) >= 1 && (x) <= 100 &&
      (y) >= 1 && (y) <= 100 &&
      (y) % 2 == 0);
    ensures \result == ((x) + ((y) / 2));
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    uint32_t result;
    //@ assert y % 2 == 0;
    result = x + (y / 2);
    //@ assert result == ((x) + ((y) / 2));
    return result;
}
