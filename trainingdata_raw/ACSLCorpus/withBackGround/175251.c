#include <stdbool.h>

/*@
    predicate same_sign(integer a, integer b) =
        (a > 0 && b > 0) || (a < 0 && b < 0) || (a == 0 && b == 0);
 */

/*@
    requires -1000 <= a <= 1000;
    requires -1000 <= b <= 1000;
    ensures \result == true <==> same_sign(a, b);
 */
bool func(int a, int b)
{
    int state;
    int state2;
    bool result;

    state = 0;
    if (a > 0) {
        state = 1;
    } else if (a < 0) {
        state = -1;
    }

    state2 = 0;
    if (b > 0) {
        state2 = 1;
    } else if (b < 0) {
        state2 = -1;
    }

    //@ assert state == 1 || state == -1 || state == 0;
    //@ assert state2 == 1 || state2 == -1 || state2 == 0;

    if (state == state2) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
