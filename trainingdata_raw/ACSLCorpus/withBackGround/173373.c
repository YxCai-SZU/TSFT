#include <stdbool.h>

/*@
    predicate is_even(integer y) = y % 2 == 0;
    predicate within_range(integer x, integer y) = 1 <= x <= 100 && 1 <= y <= 100;
    predicate result_condition(integer x, integer y) = is_even(y) && x <= 2 * y && x >= 0;
*/

/*@
    requires within_range(X, Y);
    ensures \result == true <==> result_condition(X, Y);
*/
bool func(int X, int Y)
{
    bool is_even = false;
    int temp_Y = Y;

    /*@
        loop invariant 1 <= X <= 100;
        loop invariant 1 <= Y <= 100;
        loop invariant 0 <= temp_Y <= Y;
        loop invariant temp_Y % 2 == Y % 2;
        loop assigns temp_Y;
        loop variant temp_Y;
    */
    while (temp_Y >= 2)
    {
        temp_Y -= 2;
    }

    if (temp_Y == 0)
    {
        is_even = true;
    }

    if (is_even && X <= 2 * Y && X >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
