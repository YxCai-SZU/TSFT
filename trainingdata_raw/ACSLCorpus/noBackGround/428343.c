#include <stdint.h>

/*@
    requires (0 <= (n) && (n) < 0x100000000);
    ensures \result == ((n) / 60);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t result;
    uint32_t temp_n;

    result = 0;
    temp_n = n;

    /*@
        loop invariant 0 <= result;
        loop invariant result <= ((n) / 60);
        loop invariant temp_n <= n;
        loop invariant 0 <= temp_n;
        loop invariant temp_n == n - result * 60;
        loop assigns result, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 60)
    {
        temp_n -= 60;
        result += 1;
    }

    //@ assert result * 60 + temp_n == n;

    return result;
}
