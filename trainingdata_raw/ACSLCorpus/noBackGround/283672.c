#include <stdint.h>

/*@
    requires (0 <= (a) < 0x10000000);
    ensures \result == ((a) / 16);
    ensures 0 <= \result < 0x10000000;
*/
uint32_t test_func(uint32_t a)
{
    uint32_t result;
    uint32_t count;
    uint32_t temp_a;

    result = 0;
    count = 0;
    temp_a = a;

    /*@
        loop invariant 0 <= temp_a < 0x10000000;
        loop invariant count == (a - temp_a) / 16;
        loop invariant temp_a == a - 16 * count;
        loop invariant 0 <= count < 0x10000000;
        loop assigns temp_a, count;
    */
    while (temp_a >= 16)
    {
        temp_a = temp_a - 16;
        count = count + 1;
    }

    result = count;

    //@ assert result == a / 16;
    //@ assert 0 <= result < 0x10000000;

    return result;
}
