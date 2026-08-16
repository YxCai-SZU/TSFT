#include <stdint.h>

/*@
    requires 1 <= x <= 100000;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (x / 100 * 100 + 99) / 100 == x / 100;
    ensures \result == 0 ==> (x / 100 * 100 + 99) / 100 != x / 100;
*/
int32_t func(uint32_t x)
{
    uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t result;
    int32_t ret_val;

    a = x / 100;
    b = x % 100;
    c = a * 100 + 99;
    result = c / 100;

    //@ assert a == x / 100;
    //@ assert b == x % 100;
    //@ assert c == a * 100 + 99;
    //@ assert result == c / 100;

    if (result == a)
    {
        ret_val = 1;
        //@ assert (x / 100 * 100 + 99) / 100 == x / 100;
    }
    else
    {
        //@ assert (x / 100 * 100 + 99) / 100 != x / 100;
        ret_val = 0;
    }

    return ret_val;
}
