#include <limits.h>

/*@
    predicate valid_input(integer x, integer y) =
        1 <= x <= 100 &&
        1 <= y <= 100 &&
        y % 2 == 0;

    logic integer manual_division(integer y) =
        y / 2;

    lemma division_property:
        \forall integer y; y % 2 == 0 ==> manual_division(y) == y / 2;
*/

/*@
    requires valid_input(x, y);
    ensures \result >= 0;
    ensures \result <= manual_division(y) + x;
    assigns \nothing;
*/
long func(long x, long y) {
    long ans;
    long temp_y;
    long quotient;
    long remainder;
    long abs_y;

    ans = x;
    temp_y = y;
    quotient = 0;
    remainder = 0;
    abs_y = (y < 0) ? -y : y;

    /*@
        loop invariant 0 <= abs_y <= y;
        loop invariant 0 <= quotient <= manual_division(y);
        loop invariant abs_y == y - 2 * quotient;
        loop invariant 1 <= x <= 100;
        loop assigns abs_y, quotient;
        loop variant abs_y;
    */
    while (abs_y >= 2) {
        //@ assert abs_y >= 2;
        abs_y -= 2;
        quotient += 1;
    }
    remainder = abs_y;

    if (y < 0) {
        quotient = -quotient;
    }

    ans += quotient;

    if (remainder > 0) {
        if (quotient < x) {
            ans += 1;
        }
    }

    //@ assert ans >= 0;
    //@ assert ans <= manual_division(y) + x;
    return ans;
}
