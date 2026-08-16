#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((((n)) * 800) - (((((n))) / 15) * 200));
*/
uint32_t func(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t res;
    uint32_t count;
    uint32_t temp_n;
    uint32_t ans;

    res = n * 800;
    count = 0;
    temp_n = n;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= count <= ((n) / 15);
        loop invariant res == ((n) * 800);
        loop invariant temp_n == n - 15 * count;
        loop assigns count, temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n == n - 15 * count;
        count = count + 1;
        temp_n = temp_n - 15;
        //@ assert temp_n == n - 15 * count;
    }

    ans = res - count * 200;
    //@ assert ans == ((((n)) * 800) - (((((n))) / 15) * 200));
    return ans;
}
