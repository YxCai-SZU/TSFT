#include <stddef.h>

/*@
    requires 0 <= a < 10000;
    requires 0 <= b < 10000;
    ensures b == 0 ==> \result == a;
    ensures b != 0 ==> \result <= b + (a / b) * b;
 */
size_t func(size_t a, size_t b)
{
    size_t result = 0;

    //@ assert a < 10000 && b < 10000;
    if (b == 0)
    {
        result = a;
        //@ assert result == a;
    }
    else
    {
        //@ assert a / b <= 10000;
        //@ assert b + (a / b) * b <= b + 10000 * 10000;
        result = b + (a / b) * b;
        //@ assert result <= ((b) + ((a) / (b)) * (b));
    }

    return result;
}
