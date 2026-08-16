#include <limits.h>

/*@
    requires (0 <= (length) <= INT_MAX &&
        0 <= (width) <= INT_MAX &&
        (length) * (width) <= INT_MAX);
    ensures \result == ((length) * (width));
    assigns \nothing;
*/
int rectangle_area(int length, int width) {
    //@ assert (0 <= (length) <= INT_MAX &&         0 <= (width) <= INT_MAX &&         (length) * (width) <= INT_MAX);
    //@ assert ((length) * (width)) <= INT_MAX;
    return length * width;
}
