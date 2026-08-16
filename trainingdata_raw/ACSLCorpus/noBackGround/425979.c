#include <stdint.h>

/*@
    requires ((a) >= 0) && ((b) >= 0);
    requires (0 <= (a) <= 100) && (0 <= (b) <= 100);
    ensures ((\result) >= 0);
    ensures \result <= ((a) * 100 + (b));
    ensures \result <= ((a) * 100 + (b)) / 2;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t result;
    uint32_t temp_sum;
    uint32_t count;

    sum = a * 100 + b;
    result = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum / 2;
        loop invariant temp_sum == sum - 2 * count;
        loop assigns temp_sum, count;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
    }

    result = count;
    return result;
}
