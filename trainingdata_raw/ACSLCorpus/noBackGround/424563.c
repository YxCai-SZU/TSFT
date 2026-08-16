#include <stdint.h>

/*@
    requires 1 <= n && n <= 100;
    ensures \result == n * 800 - (n / 15) * 200;
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t ans = 0;
    uint32_t temp_n = n;

    /*@
        loop invariant 0 <= temp_n && temp_n <= n;
        loop invariant ans == (((n) - (temp_n)) * 200 / 15);
        loop invariant temp_n + 15 * (ans / 200) == n;
        loop invariant ans >= 0;
        loop invariant temp_n >= 0;
        loop assigns ans, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        ans += 200;
        temp_n -= 15;
    }

    //@ assert n * 800 <= 100 * 800;
    //@ assert ans <= 200 * 100;

    return (int32_t)(n * 800 - ans);
}
