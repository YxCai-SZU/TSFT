#include <stddef.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
    ensures \result == (((a) + (b)) * (h) / 2);
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t h)
{
    // Variable declarations at top of scope
    size_t sum;
    size_t ans;
    size_t i;
    size_t half_sum;
    size_t sum_copy;

    //@ assert (1 <= (a) <= 100 &&         1 <= (b) <= 100 &&         1 <= (h) <= 100 &&         (h) % 2 == 0);
    
    sum = (a + b) * h;
    ans = 0;
    i = 0;
    half_sum = 0;
    sum_copy = sum;

    //@ assert sum == (a + b) * h;
    
    /*@
        loop invariant 0 <= sum_copy <= sum;
        loop invariant half_sum <= sum / 2;
        loop invariant sum_copy + 2 * half_sum == sum;
        loop invariant (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
        loop assigns sum_copy, half_sum;
        loop variant sum_copy;
    */
    while (sum_copy >= 2)
    {
        //@ assert sum_copy >= 2;
        sum_copy -= 2;
        half_sum += 1;
        //@ assert sum_copy + 2 * half_sum == sum;
    }

    ans = half_sum;
    //@ assert ans == (((a) + (b)) * (h) / 2);
    return ans;
}
