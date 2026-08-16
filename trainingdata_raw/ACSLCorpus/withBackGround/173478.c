#include <limits.h>

/*@
    predicate valid_input(integer x, integer y) =
        1 <= x <= 100 &&
        1 <= y <= 100 &&
        y % 2 == 0;

    logic integer half(integer y) = y / 2;

    predicate non_negative_result(integer res) = res >= 0;
*/

/*@
    requires valid_input(x, y);
    ensures non_negative_result(\result);
    ensures \result == x + half(y);
*/
int func(int x, int y)
{
    int ans;
    int temp_y;
    int quotient;
    int remainder;
    int abs_y;

    ans = x;
    temp_y = y;
    quotient = 0;
    remainder = 0;
    abs_y = (y < 0) ? -y : y;

    /*@
        loop invariant 0 <= abs_y <= y;
        loop invariant quotient >= 0;
        loop invariant abs_y == y - 2 * quotient;
        loop assigns abs_y, quotient;
    */
    while (abs_y >= 2)
    {
        abs_y -= 2;
        quotient += 1;
    }
    remainder = abs_y;

    if (y < 0)
    {
        quotient = -quotient;
    }

    ans += quotient;
    return ans;
}
