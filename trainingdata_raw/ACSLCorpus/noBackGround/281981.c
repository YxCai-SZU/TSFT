#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
    ensures \result == (((a) + (b)) * (h) / 2);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t h)
{
    //@ assert (1 <= (a) <= 100 &&         1 <= (b) <= 100 &&         1 <= (h) <= 100 &&         (h) % 2 == 0);
    
    int64_t sum = (a + b) * h;
    int64_t result = 0;
    int64_t temp_sum = sum;
    int64_t count = 0;
    
    //@ assert 2 <= sum <= 20000;
    
    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum / 2;
        loop invariant sum == temp_sum + 2 * count;
        loop invariant (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
        //@ assert sum == temp_sum + 2 * count;
    }
    
    result = count;
    //@ assert result == (((a) + (b)) * (h) / 2);
    return result;
}
