#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == (x * 4 >= y && y % 2 == 0);
*/
bool func(int x, int y)
{
    bool is_divisible_by_2 = false;
    int temp_y = y;

    //@ ghost int original_y = y;

    /*@
        loop invariant 1 <= original_y <= 100;
        loop invariant ((temp_y) >= 0 && (temp_y) <= (original_y) && (temp_y) % 2 == (original_y) % 2);
        loop assigns temp_y;
        loop variant temp_y;
    */
    while (temp_y >= 2)
    {
        //@ assert temp_y >= 2;
        temp_y -= 2;
    }

    if (temp_y == 0)
    {
        is_divisible_by_2 = true;
    }

    //@ assert is_divisible_by_2 == (y % 2 == 0);

    int x_four_times = x * 4;
    //@ assert x_four_times == x * 4;

    if (x_four_times >= y && is_divisible_by_2)
    {
        //@ assert x * 4 >= y && y % 2 == 0;
        return true;
    }
    else
    {
        //@ assert !(x * 4 >= y && y % 2 == 0);
        return false;
    }
}

