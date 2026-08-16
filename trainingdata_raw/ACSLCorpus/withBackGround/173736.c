#include <stdbool.h>

/*@
    predicate is_valid_range(integer x, integer y) =
        1 <= x && x < y && y < 100;

    logic integer diff(integer x, integer y) =
        x < y ? y - x : x - y;

    lemma diff_property:
        \forall integer x, y;
            is_valid_range(x, y) ==> diff(x, y) == y - x;
*/

/*@
    requires is_valid_range(x, y);
    ensures \result == (x < y && (y - x >= 1 && y - x <= 99));
    assigns \nothing;
*/
bool func(int x, int y)
{
    int diff;
    /*@ assert is_valid_range(x, y); */
    //@ assert x < y;
    diff = y - x;
    /*@ assert diff == y - x; */
    //@ assert diff >= 1 && diff <= 99;
    return diff <= 99;
}
