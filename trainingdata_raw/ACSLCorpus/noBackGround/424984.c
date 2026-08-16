#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == true <==> (x % 2 == 0 && y % 2 == 0 && (y - x) % 2 == 0);
    assigns \nothing;
*/
bool func(int x, int y)
{
    int x_abs;
    int y_abs;
    bool is_x_even;
    bool is_y_even;
    int diff;
    bool is_diff_even;
    int temp_x;
    int temp_y;
    int temp_diff;

    x_abs = (x < 0) ? -x : x;
    y_abs = (y < 0) ? -y : y;

    temp_x = x_abs;
    /*@
        loop invariant 0 <= temp_x <= x_abs;
        loop invariant x_abs >= 1 && x_abs <= 100;
        loop invariant temp_x % 2 == x_abs % 2;
        loop assigns temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 2)
    {
        temp_x -= 2;
    }
    is_x_even = (temp_x == 0);

    temp_y = y_abs;
    /*@
        loop invariant 0 <= temp_y <= y_abs;
        loop invariant y_abs >= 1 && y_abs <= 100;
        loop invariant temp_y % 2 == y_abs % 2;
        loop assigns temp_y;
        loop variant temp_y;
    */
    while (temp_y >= 2)
    {
        temp_y -= 2;
    }
    is_y_even = (temp_y == 0);

    if (!(is_x_even && is_y_even))
    {
        return false;
    }

    diff = (y_abs > x_abs) ? (y_abs - x_abs) : (x_abs - y_abs);

    temp_diff = diff;
    /*@
        loop invariant 0 <= temp_diff <= diff;
        loop invariant diff >= 0 && diff <= 100;
        loop invariant temp_diff % 2 == diff % 2;
        loop assigns temp_diff;
        loop variant temp_diff;
    */
    while (temp_diff >= 2)
    {
        temp_diff -= 2;
    }
    is_diff_even = (temp_diff == 0);

    //@ assert is_x_even == (x_abs % 2 == 0);
    //@ assert is_y_even == (y_abs % 2 == 0);
    //@ assert is_diff_even == (diff % 2 == 0);
    //@ assert (x_abs % 2 == 0 && y_abs % 2 == 0 && (y_abs - x_abs) % 2 == 0) <==> (is_x_even && is_y_even && is_diff_even);

    if (is_diff_even)
    {
        return true;
    }
    else
    {
        return false;
    }
}
