#include <stdint.h>

/*@
    requires 1 <= x <= 10;
    requires 1 <= y <= 10;
    ensures \result == x * y - 5 * (x - 1);
*/
int32_t func(int32_t x, int32_t y)
{
    int32_t result;

    //@ assert (1 <= (x) <= 10 && 1 <= (y) <= 10);
    //@ assert 1 <= x * y <= 100;
    //@ assert 0 <= 5 * (x - 1) <= 45;

    result = x * y - 5 * (x - 1);
    //@ assert result == ((((x)) * ((y))) - (5 * (((x)) - 1)));
    return result;
}
