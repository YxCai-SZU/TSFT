#include <limits.h>

/*@
    predicate is_valid_input(integer x, integer y) =
        1 <= x <= 100 &&
        1 <= y <= 100 &&
        y % 2 == 0;

    logic integer target_result(integer x, integer y) = x + (y / 2);

    lemma division_property: \forall integer y; y % 2 == 0 ==> y / 2 * 2 == y;
*/

/*@
    requires is_valid_input(x, y);
    ensures \result == target_result(x, y);
    assigns \nothing;
*/
int func(int x, int y) {
    int ans;
    int temp_y;
    int quotient;
    int remainder;
    int abs_y;
    int res;
    int temp_ans;

    ans = x;
    temp_y = y;
    quotient = 0;
    remainder = 0;

    if (temp_y < 0) {
        abs_y = -temp_y;
    } else {
        abs_y = temp_y;
    }

    /*@
        loop invariant 0 <= abs_y <= y;
        loop invariant 0 <= quotient <= y / 2;
        loop invariant abs_y == y - 2 * quotient;
        loop invariant 1 <= x <= 100;
        loop invariant 1 <= y <= 100;
        loop assigns abs_y, quotient;
        loop variant abs_y;
    */
    while (abs_y >= 2) {
        abs_y -= 2;
        quotient += 1;
    }
    remainder = abs_y;

    if (temp_y < 0) {
        quotient = -quotient;
    }

    res = ans;
    temp_ans = quotient;

    /*@
        loop invariant 0 <= temp_ans <= quotient;
        loop invariant res == ans + (quotient - temp_ans);
        loop invariant 1 <= x <= 100;
        loop invariant 1 <= y <= 100;
        loop assigns res, temp_ans;
        loop variant temp_ans;
    */
    while (temp_ans > 0) {
        //@ assert temp_ans > 0;
        res += 1;
        temp_ans -= 1;
    }

    //@ assert res == ans + quotient;
    //@ assert quotient == y / 2;
    //@ assert res == x + (y / 2);
    return res;
}
