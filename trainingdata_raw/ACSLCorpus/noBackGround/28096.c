#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures \result >= 0;
    ensures \result <= ((a) + (b) + 1);
    ensures ((a) + (b) + 1) / 2 == \result;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t sum;
    int64_t ans;
    int64_t count;
    int64_t temp_sum;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100);
    sum = a + b + 1;
    ans = 0;
    count = 0;
    temp_sum = sum;

    /*@
        loop invariant 1 <= a && a <= 100;
        loop invariant 1 <= b && b <= 100;
        loop invariant sum == ((a) + (b) + 1);
        loop invariant temp_sum >= 0;
        loop invariant temp_sum <= sum;
        loop invariant ans >= 0;
        loop invariant ans == (sum - temp_sum) / 2;
        loop invariant count == (sum - temp_sum) / 2;
        loop invariant sum == temp_sum + 2 * count;
        loop assigns temp_sum, ans, count;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        ans += 1;
        count += 1;
        //@ assert ans == (sum - temp_sum) / 2;
    }

    //@ assert ans == sum / 2;
    return ans;
}
