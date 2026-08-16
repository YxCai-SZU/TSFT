#include <stdint.h>

/*@
    requires -1290 <= x <= 1290;
    ensures \result == ((x) * (x) * (x));
    ensures (-9223372036854775808 <= (\result) <= 9223372036854775807);
*/
int64_t func(int64_t x)
{
    int64_t x_squared;
    int64_t result;

    //@ assert (-9223372036854775808 <= (x * x) <= 9223372036854775807);
    x_squared = x * x;

    //@ assert (-9223372036854775808 <= (x * x_squared) <= 9223372036854775807);
    result = x * x_squared;

    //@ assert result == ((x) * (x) * (x));
    return result;
}
