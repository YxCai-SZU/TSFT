#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 1000000000000000);
    ensures \result >= 0;
    ensures \result <= 2 * (x / 11) + 2;
*/
int64_t func(int64_t x)
{
    int64_t temp_x;
    int64_t cnt;
    int64_t ans;

    temp_x = x;
    cnt = 0;

    /*@
        loop invariant (1 <= (x) && (x) <= 1000000000000000);
        loop invariant 0 <= cnt <= x / 11;
        loop invariant temp_x == ((x) - 11 * (cnt));
        loop assigns temp_x, cnt;
    */
    while (temp_x >= 11)
    {
        //@ assert temp_x >= 11;
        temp_x -= 11;
        cnt += 1;
    }

    //@ assert 0 <= temp_x < 11;
    if (temp_x > 6)
    {
        ans = cnt * 2 + 2;
    }
    else
    {
        ans = cnt * 2 + 1;
    }

    //@ assert ans >= 0;
    return ans;
}
