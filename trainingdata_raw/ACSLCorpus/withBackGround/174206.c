#include <stdbool.h>

/*@
    predicate is_valid_params(integer x, integer y) =
        1 <= x <= 100 &&
        1 <= y <= 100 &&
        y % 2 == 0;

    logic integer half_y(integer y) = y / 2;

    lemma half_y_property:
        \forall integer y; is_valid_params(100, y) ==> half_y(y) == y / 2;
*/

/*@
    requires is_valid_params(x, y);
    ensures \result == x + (y / 2);
    assigns \nothing;
*/
long func(long x, long y) {
    long result;
    long temp_y;
    long quotient;
    long remainder;
    long abs_y;
    
    result = x;
    temp_y = y;
    quotient = 0;
    remainder = 0;
    
    if (y < 0) {
        abs_y = -y;
    } else {
        abs_y = y;
    }
    
    /*@
        loop invariant 0 <= abs_y <= 100;
        loop invariant 0 <= quotient <= 50;
        loop invariant abs_y == y - 2 * quotient;
        loop invariant 1 <= x <= 100;
        loop invariant 1 <= y <= 100;
        loop invariant y % 2 == 0;
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
    
    result += quotient;
    
    //@ assert result == x + (y / 2);
    return result;
}
