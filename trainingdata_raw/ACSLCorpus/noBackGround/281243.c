#include <limits.h>

/*@
    requires (1 <= (x) <= 100 &&
        1 <= (y) <= 100 &&
        (y) % 2 == 0);
    ensures \result == x + (y / 2);
    assigns \nothing;
*/
long func(long x, long y)
{
    long half_y;
    long sum;
    long count;
    long temp_y;

    //@ assert (1 <= (x) <= 100 &&         1 <= (y) <= 100 &&         (y) % 2 == 0);

    if (y >= 0)
    {
        sum = 0;
        count = 0;
        temp_y = y;

        /*@
            loop invariant 0 <= temp_y <= y;
            loop invariant 0 <= count <= y / 2;
            loop invariant sum == count;
            loop invariant temp_y == y - 2 * count;
            loop invariant (1 <= (x) <= 100 &&
        1 <= (y) <= 100 &&
        (y) % 2 == 0);
            loop assigns sum, count, temp_y;
            loop variant temp_y;
        */
        while (temp_y >= 2)
        {
            //@ assert temp_y >= 2;
            sum += 1;
            temp_y -= 2;
            count += 1;
        }
        half_y = sum;
    }
    else
    {
        sum = 0;
        count = 0;
        temp_y = y;

        /*@
            loop invariant -2 < temp_y <= y;
            loop invariant 0 <= count <= (y - temp_y) / 2;
            loop invariant sum == -count;
            loop invariant temp_y == y - 2 * count;
            loop invariant (1 <= (x) <= 100 &&
        1 <= (y) <= 100 &&
        (y) % 2 == 0);
            loop assigns sum, count, temp_y;
            loop variant -temp_y;
        */
        while (temp_y <= -2)
        {
            //@ assert temp_y <= -2;
            sum -= 1;
            temp_y += 2;
            count += 1;
        }
        half_y = sum;
    }

    //@ assert half_y == y / 2;
    long ans = x + half_y;
    //@ assert ans == x + (y / 2);
    return ans;
}
