#include <limits.h>

/*@ predicate is_valid_x(integer x) = 0 <= x <= 1; */

/*@
    requires is_valid_x(x);
    ensures \result == 1 - x;
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(int x) {
    //@ assert 0 <= x <= 1;
    int result;
    //@ assert 1 - x == 1 - x;
    result = 1 - x;
    return result;
}
