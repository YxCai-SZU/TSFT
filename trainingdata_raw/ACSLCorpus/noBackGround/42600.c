#include <stdint.h>

/*@
    requires ((a) >= 1 && (a) <= 100 &&
        (b) >= 1 && (b) <= 100 &&
        (c) >= 1 && (c) <= 100);
    ensures \result == (a + b + c) / 3;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    // Variable declarations at top
    uint32_t sum_val;
    uint32_t result;
    uint32_t temp_sum;
    uint32_t count;

    //@ assert ((a) >= 1 && (a) <= 100 &&         (b) >= 1 && (b) <= 100 &&         (c) >= 1 && (c) <= 100);
    //@ assert ((a) + (b) + (c)) <= 300;

    sum_val = a + b + c;
    result = 0;
    temp_sum = sum_val;
    count = 0;

    /*@
        loop invariant temp_sum >= 0;
        loop invariant temp_sum + 3 * count == sum_val;
        loop invariant count <= sum_val / 3;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 3)
    {
        temp_sum = temp_sum - 3;
        count = count + 1;
    }

    result = count;
    //@ assert result == (a + b + c) / 3;
    return result;
}
