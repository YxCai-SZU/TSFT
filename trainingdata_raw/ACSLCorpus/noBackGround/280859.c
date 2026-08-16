#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (a * b) / 2;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t result;
    uint32_t temp_result;
    uint32_t count;
    int is_even_flag;

    //@ assert a * b <= 10000;

    result = a * b;
    count = 0;
    is_even_flag = 0;

    // Check if product is even
    temp_result = result;
    /*@
        loop invariant 0 <= temp_result <= a * b;
        loop invariant temp_result == result - 2 * ((result - temp_result) / 2);
        loop assigns temp_result;
        loop variant temp_result;
    */
    while (temp_result >= 2)
    {
        temp_result -= 2;
    }

    if (temp_result == 0)
    {
        is_even_flag = 1;
    }

    // Division by 2 using subtraction
    /*@
        loop invariant 0 <= result <= a * b;
        loop invariant 0 <= count <= (a * b) / 2;
        loop invariant result == a * b - 2 * count;
        loop assigns result, count;
        loop variant result;
    */
    while (result >= 2)
    {
        result -= 2;
        count += 1;
    }

    //@ assert count == (a * b) / 2;
    return (int32_t)count;
}
