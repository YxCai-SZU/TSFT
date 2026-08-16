#include <stdbool.h>

/*@
    requires \valid(xs + (0 .. 1));
    requires ((2) == 2 &&
        1 <= (xs)[0] <= 100 &&
        1 <= (xs)[1] <= 100);
    ensures \result >= 0;
    ensures \result == xs[0] - (xs[1] * 2) || \result == 0;
    assigns \nothing;
*/
int func(int *xs) {
    int result;
    result = 0;

    //@ assert xs[0] >= 1 && xs[0] <= 100;
    //@ assert xs[1] >= 1 && xs[1] <= 100;

    if (xs[0] > (xs[1] * 2)) {
        result = xs[0] - (xs[1] * 2);
    }

    //@ assert result >= 0;
    //@ assert result == xs[0] - (xs[1] * 2) || result == 0;
    return result;
}
