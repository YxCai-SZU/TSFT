#include <stdint.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == 0 ==> ((a * b) % 2 == 0);
    ensures \result == 1 ==> !((a * b) % 2 == 0);
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t c;
    int32_t is_even_flag;
    int32_t result;

    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    //@ assert a * b <= 10000 * 10000;

    c = a * b;
    is_even_flag = (c % 2 == 0) ? 1 : 0;

    if (is_even_flag)
    {
        result = 0;
    }
    else
    {
        result = 1;
    }

    return result;
}
