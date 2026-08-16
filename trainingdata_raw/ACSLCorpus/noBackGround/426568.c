#include <limits.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == 3 * r * r;
    assigns \nothing;
*/
int func(int r) {
    int result;

    //@ assert (1 <= (r) <= 100);
    //@ assert 3 * r * r <= INT_MAX;
    //@ assert 3 * r * r >= 0;

    result = 3 * r * r;
    return result;
}
