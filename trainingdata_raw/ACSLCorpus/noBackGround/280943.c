#include <stdbool.h>

/*@
    requires \valid_read(xs + (0..2));
    requires (1 <= (xs[0]) && (xs[0]) <= 100) && (1 <= (xs[1]) && (xs[1]) <= 100) && (1 <= (xs[2]) && (xs[2]) <= 100);
    ensures \result == (xs[1] - xs[0] == xs[2] - xs[1]);
*/
bool func(const int xs[3])
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (1 <= (xs[0]) && (xs[0]) <= 100);
    //@ assert (1 <= (xs[1]) && (xs[1]) <= 100);
    //@ assert (1 <= (xs[2]) && (xs[2]) <= 100);
    //@ assert (-99 <= ((int)(xs[1] - xs[0])) && ((int)(xs[1] - xs[0])) <= 99);
    //@ assert (-99 <= ((int)(xs[2] - xs[1])) && ((int)(xs[2] - xs[1])) <= 99);

    result = (xs[1] - xs[0] == xs[2] - xs[1]);
    return result;
}
