#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == true <==> (2 * x <= y && y % 2 == 0);
    assigns \nothing;
*/
bool func(int x, int y)
{
    bool is_even_var = false;
    int temp_y = y;

    /*@
        loop invariant 0 <= temp_y <= y;
        loop invariant temp_y % 2 == y % 2;
        loop assigns temp_y;
        loop variant temp_y;
    */
    while (temp_y >= 2)
    {
        temp_y -= 2;
    }

    //@ assert temp_y == 0 || temp_y == 1;
    if (temp_y == 0)
    {
        is_even_var = true;
    }

    //@ assert is_even_var == (y % 2 == 0);
    if (2 * x <= y && is_even_var)
    {
        return true;
    }
    else
    {
        return false;
    }
}
