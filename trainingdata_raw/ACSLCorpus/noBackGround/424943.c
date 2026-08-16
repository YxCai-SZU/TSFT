#include <stdbool.h>

/*@
    requires (1 <= (X) <= 100) && (1 <= (Y) <= 100) && ((Y) % 2 == 0);
    ensures \result == X + ((Y) / 2);
*/
int func(int X, int Y)
{
    int ans = X;
    int temp_Y = Y;
    int count = 0;
    bool is_negative = false;

    if (temp_Y < 0)
    {
        is_negative = true;
        temp_Y = -temp_Y;
    }

    /*@
        loop invariant (1 <= (X) <= 100);
        loop invariant (1 <= (Y) <= 100);
        loop invariant ((Y) % 2 == 0);
        loop invariant (0 <= (temp_Y) <= (Y));
        loop invariant ((count) >= 0);
        loop invariant ((temp_Y) == (Y) - 2 * (count));
        loop assigns temp_Y, count;
    */
    while (temp_Y >= 2)
    {
        temp_Y -= 2;
        count += 1;
    }

    if (is_negative)
    {
        count = -count;
    }

    ans += count;

    //@ assert ans == X + ((Y) / 2);

    return ans;
}
