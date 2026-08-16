#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> (a + b) % 2 != 0;
    ensures \result == 1 ==> (a + b) % 2 == 0;
*/
int64_t func(uint64_t a, uint64_t b)
{
    uint64_t sum;
    uint64_t temp_sum;
    int is_even;
    int64_t result;

    sum = a + b;
    is_even = 1;
    temp_sum = sum;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    //@ assert sum == a + b;
    //@ assert 2 <= sum <= 200;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant temp_sum <= sum;
        loop invariant sum == a + b;
        loop invariant (sum - temp_sum) % 2 == 0;
        loop invariant temp_sum >= 0;
        loop invariant temp_sum <= 200;
        loop assigns temp_sum;
    */
    while (temp_sum > 1)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        //@ assert (sum - temp_sum) % 2 == 0;
    }

    if (temp_sum != 0)
    {
        is_even = 0;
    }

    if (is_even)
    {
        //@ assert (a + b) % 2 == 0;
        result = 1;
    }
    else
    {
        //@ assert (a + b) % 2 != 0;
        result = 0;
    }

    return result;
}
