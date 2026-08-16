#include <stdbool.h>

/*@
    predicate valid_input(integer x, integer y) =
        1 <= x <= 100 &&
        1 <= y <= 100 &&
        y % 2 == 0;

    logic integer half_of(integer y) = y / 2;

    logic integer expected_result(integer x, integer y) = x + half_of(y);
*/

/*@
    requires valid_input(x, y);
    ensures \result == expected_result(x, y);
    assigns \nothing;
*/
long func(long x, long y)
{
    long half_y = 0;
    long i = 0;
    bool is_even = false;
    long temp_y = y;
    long ans = 0;
    long j = 0;

    //@ assert valid_input(x, y);

    /*@
        loop invariant 0 <= temp_y <= y;
        loop invariant half_y <= half_of(y);
        loop invariant temp_y == y - 2 * half_y;
        loop invariant half_y >= 0;
        loop assigns half_y, temp_y;
    */
    while (temp_y >= 2)
    {
        //@ assert temp_y >= 2;
        half_y += 1;
        temp_y -= 2;
    }

    if (temp_y == 0)
    {
        is_even = true;
    }

    //@ assert half_y == half_of(y);

    ans = x;
    j = 0;

    /*@
        loop invariant 0 <= j <= half_y;
        loop invariant ans == x + j;
        loop invariant ans <= x + half_y;
        loop invariant ans >= x;
        loop assigns ans, j;
    */
    while (j < half_y)
    {
        //@ assert j < half_y;
        ans += 1;
        j += 1;
    }

    //@ assert ans == expected_result(x, y);
    return ans;
}
