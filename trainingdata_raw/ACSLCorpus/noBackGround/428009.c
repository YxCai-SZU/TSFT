#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - (n) / 15 * 200);
*/
uint32_t func(uint32_t n)
{
    // Variable declarations
    uint32_t x;
    uint32_t result;
    uint32_t count;
    uint32_t temp_n;

    // Initial assignments
    x = n * 800;
    result = x;
    count = 0;
    temp_n = n;

    /*@
        loop invariant 0 <= temp_n && temp_n <= n;
        loop invariant 0 <= count && count <= n / 15;
        loop invariant result == x;
        loop invariant x == n * 800;
        loop invariant temp_n + 15 * count == n;
        loop assigns count, temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        count += 1;
        temp_n -= 15;
    }

    result -= count * 200;
    //@ assert result == ((n) * 800 - (n) / 15 * 200);
    return result;
}
