#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result >= 0;
    ensures \result <= n;
    ensures \result == 0 ==> n != 1;
    ensures \result == 1 ==> n == 1;
*/
int32_t func(uint32_t n)
{
    int32_t result;

    if (n == 1)
    {
        //@ assert n == 1;
        result = 1;
    }
    else
    {
        //@ assert n != 1;
        result = 0;
    }

    return result;
}
