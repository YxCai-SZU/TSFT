#include <limits.h>

/*@
    predicate is_valid_input(integer X, integer Y) =
        1 <= X <= 100 &&
        1 <= Y <= 100 &&
        Y % 2 == 0;

    logic integer half(integer Y) = Y / 2;

    logic integer expected_result(integer X, integer Y) = X + half(Y);
*/

/*@
    requires is_valid_input(X, Y);
    ensures \result == expected_result(X, Y);
    assigns \nothing;
*/
int func(int X, int Y)
{
    int ans;
    int temp_y;
    int quotient;
    int remainder;
    int abs_y;

    ans = X;
    temp_y = Y;
    quotient = 0;
    remainder = 0;
    abs_y = (temp_y < 0) ? -temp_y : temp_y;

    /*@
        loop invariant 0 <= abs_y <= Y;
        loop invariant 0 <= quotient <= Y / 2;
        loop invariant abs_y == Y - 2 * quotient;
        loop assigns abs_y, quotient;
        loop variant abs_y;
    */
    while (abs_y >= 2)
    {
        //@ assert abs_y >= 2;
        abs_y -= 2;
        quotient += 1;
    }
    remainder = abs_y;

    if (temp_y < 0)
    {
        quotient = -quotient;
    }

    ans += quotient;
    //@ assert ans == X + Y / 2;
    return ans;
}
