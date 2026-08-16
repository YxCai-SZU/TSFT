#include <limits.h>

/*@
    requires (1 <= (x) && (x) <= 100) && (1 <= (y) && (y) <= 100) && ((y) % 2 == 0);
    ensures \result == x + (y / 2);
    assigns \nothing;
*/
int func(int x, int y)
{
    int half_y;
    int count;
    int temp_y;

    if (y >= 0)
    {
        count = 0;
        temp_y = y;
        /*@
            loop invariant temp_y >= 0;
            loop invariant count >= 0;
            loop invariant temp_y == y - 2 * count;
            loop assigns temp_y, count;
            loop variant temp_y;
        */
        while (temp_y >= 2)
        {
            temp_y -= 2;
            count += 1;
        }
        half_y = count;
    }
    else
    {
        count = 0;
        temp_y = y;
        /*@
            loop invariant temp_y <= 0;
            loop invariant count <= 0;
            loop invariant temp_y == y - 2 * count;
            loop assigns temp_y, count;
            loop variant -temp_y;
        */
        while (temp_y <= -2)
        {
            temp_y += 2;
            count -= 1;
        }
        half_y = count;
    }

    //@ assert half_y == y / 2;
    int res = x + half_y;
    return res;
}
