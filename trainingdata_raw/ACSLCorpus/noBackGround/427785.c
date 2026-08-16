#include <stdint.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (p) <= 100);
    ensures \result >= 0;
    ensures \result <= ((a) * 3 + (p));
*/
int64_t func(int64_t a, int64_t p)
{
    int64_t sum;
    int64_t result;
    int64_t temp_sum;
    int64_t count;

    sum = a * 3 + p;
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
    //@ assert result >= 0;
    //@ assert result <= ((a) * 3 + (p));
    return result;
}
