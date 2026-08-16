#include <stdbool.h>
/*@
    requires 0 <= x <= 1000000000;
    ensures \result >= 0;
    ensures \result <= 2 * (x / 11) + 2;
    assigns \nothing;
*/
int func(int x)
{
    int res;
    int temp_x;
    int count;

    res = 0;
    temp_x = x;
    count = 0;

    /*@
        loop invariant (0 <= (temp_x) <= (x) &&
        0 <= (count) <= (x) / 11 &&
        (temp_x) == (x) - 11 * (count));
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 11)
    {
        temp_x -= 11;
        count += 1;
        //@ assert (0 <= (temp_x) <= (x) &&         0 <= (count) <= (x) / 11 &&         (temp_x) == (x) - 11 * (count));
    }
    res += count * 2;

    if (temp_x > 0)
    {
        res += 1;
        //@ assert res >= 1;
    }

    if (temp_x == 10)
    {
        res += 1;
        //@ assert res >= 2;
    }

    //@ assert res >= 0;
    //@ assert res <= 2 * (x / 11) + 2;
    return res;
}
