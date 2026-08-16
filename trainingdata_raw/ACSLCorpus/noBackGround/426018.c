#include <stdbool.h>

/*@
    requires (0 <= (x) <= 100000000000000000 &&
        (x) <= (y) <= 100000000000000000);
    ensures \result == (((y - x) % 2) == 0);
    assigns \nothing;
*/
bool func(long long x, long long y) {
    long long diff;
    bool is_even;
    long long abs_diff;

    diff = y - x;
    is_even = false;
    //@ assert diff >= 0;
    if (diff < 0) {
        abs_diff = -diff;
    } else {
        abs_diff = diff;
    }

    /*@
        loop invariant 0 <= abs_diff <= 100000000000000000;
        loop invariant abs_diff <= y - x;
        loop invariant ((y - x) % 2) == ((abs_diff) % 2);
        loop assigns abs_diff;
        loop variant abs_diff;
    */
    while (abs_diff >= 2) {
        abs_diff -= 2;
    }

    //@ assert ((y - x) % 2) == ((abs_diff) % 2);
    if (abs_diff == 0) {
        is_even = true;
    }
    return is_even;
}
