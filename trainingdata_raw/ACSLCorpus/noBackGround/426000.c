#include <limits.h>

/*@
    requires (1 <= (x) <= 100 &&
        1 <= (y) <= 100 &&
        (y) % 2 == 0);
    ensures \result >= 0;
    ensures \result == x + ((y) / 2) || \result == x - ((y) / 2);
*/
int func(int x, int y)
{
    int ans = 0;
    int temp_y = y;
    int count = 0;
    int y_div_2_local = 0;
    int x_plus_y_div_2 = 0;
    int x_minus_y_div_2 = 0;

    /*@
        loop invariant 1 <= x <= 100;
        loop invariant 1 <= y <= 100;
        loop invariant y % 2 == 0;
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

    y_div_2_local = count;
    x_plus_y_div_2 = x + y_div_2_local;
    x_minus_y_div_2 = x - y_div_2_local;

    //@ assert y_div_2_local == ((y) / 2);

    if (x_plus_y_div_2 >= x_minus_y_div_2)
    {
        ans = x_plus_y_div_2;
    }
    else
    {
        ans = x_minus_y_div_2;
    }

    //@ assert ans == x + ((y) / 2) || ans == x - ((y) / 2);
    return ans;
}
