#include <limits.h>

/*@
    predicate valid_input(integer x, integer y) =
        1 <= x <= 100 &&
        1 <= y <= 100 &&
        y % 2 == 0;

    predicate loop_inv(integer x, integer y, integer temp_y, integer half_y) =
        valid_input(x, y) &&
        temp_y >= 0 &&
        half_y >= 0 &&
        half_y <= y / 2 &&
        temp_y + 2 * half_y == y &&
        temp_y <= y;

    logic integer compute_result(integer x, integer y) = x + y / 2;

    lemma result_nonnegative: \forall integer x, y; valid_input(x, y) ==> compute_result(x, y) >= 0;
    lemma result_bounded: \forall integer x, y; valid_input(x, y) ==> compute_result(x, y) <= 200;
*/

/*@
    requires valid_input(x, y);
    ensures \result >= 0;
    ensures \result == compute_result(x, y);
    assigns \nothing;
*/
int func(int x, int y)
{
    int res;
    int half_y;
    int i;
    int temp_y;

    res = x;
    half_y = 0;
    i = 0;
    temp_y = y;

    /*@
        loop invariant loop_inv(x, y, temp_y, half_y);
        loop assigns temp_y, half_y;
        loop variant temp_y;
    */
    while (temp_y >= 2)
    {
        half_y = half_y + 1;
        temp_y = temp_y - 2;
    }

    //@ assert half_y == y / 2;
    //@ assert x + half_y >= 0;
    //@ assert x + half_y <= 200;

    res = x + half_y;

    //@ assert res >= 0;
    //@ assert res <= 200;
    //@ assert res == compute_result(x, y);

    return res;
}
