#include <stdint.h>

/*@
    requires (1 <= (a) <= 20 && 1 <= (b) <= 20);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t result;
    uint32_t count;
    uint32_t temp_sum;

    sum = a + b;
    result = 0;
    count = 0;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant sum == a + b;
        loop invariant 0 <= count <= sum / 2;
        loop invariant temp_sum == sum - 2 * count;
        loop invariant (1 <= (a) <= 20 && 1 <= (b) <= 20);
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        count += 1;
    }

    if (temp_sum == 1)
    {
        count += 1;
    }

    result = count;
    return result;
}
