#include <stdint.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == ((n) * 800 - (((n)) / 15) * 200);
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    int64_t result;
    int64_t i;
    int64_t count;
    int64_t temp_n;

    // Variable declarations at scope top
    result = n * 800;
    i = 0;
    count = 0;
    temp_n = n;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= count <= ((n) / 15);
        loop invariant temp_n == n - 15 * count;
        loop invariant (1 <= (n) <= 100);
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        temp_n -= 15;
        count += 1;
    }

    //@ assert count == ((n) / 15);
    result -= count * 200;
    //@ assert result == ((n) * 800 - (((n)) / 15) * 200);
    return result;
}
