#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
    ensures \result == (a + b) * h / 2;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t h)
{
    // Variable declarations at top
    uint64_t sum_val;
    uint64_t area = 0;
    uint64_t i = 0;
    uint64_t temp_sum;

    //@ assert 2 <= a + b <= 200;
    //@ assert 2 <= (a + b) * h <= 20000;

    sum_val = (a + b) * h;
    temp_sum = sum_val;

    /*@
        loop invariant 0 <= temp_sum <= sum_val;
        loop invariant 0 <= area <= sum_val / 2;
        loop invariant temp_sum + 2 * area == sum_val;
        loop invariant area <= (a + b) * h / 2;
        loop assigns temp_sum, area;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        area += 1;
    }

    return area;
}
