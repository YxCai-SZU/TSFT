#include <stdint.h>

/*@
  requires (0 <= (x) <= 1);
  ensures \result == (1 - (x));
*/
uint32_t func(uint32_t x)
{
    //@ assert (0 <= (x) <= 1);
    uint32_t res = 1 - x;
    //@ assert res == (1 - (x));
    return res;
}
