#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 3 &&
        1 <= (b) && (b) <= 3 &&
        (a) != (b));
    ensures ((\result) == (6 - ((a)) - ((b))) &&
        1 <= (\result) && (\result) <= 3 &&
        (\result) != (a) &&
        (\result) != (b));
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b)
{
    uint64_t ans;

    //@ assert (1 <= (a) && (a) <= 3 &&         1 <= (b) && (b) <= 3 &&         (a) != (b));

    if (a == 1 && b == 2) {
        ans = 3;
    } else if (a == 2 && b == 3) {
        ans = 1;
    } else if (a == 3 && b == 1) {
        ans = 2;
    } else if (a == 2 && b == 1) {
        ans = 3;
    } else if (a == 3 && b == 2) {
        ans = 1;
    } else {
        ans = 2;
    }

    //@ assert ans == 6 - a - b;
    //@ assert 1 <= ans && ans <= 3;
    //@ assert ans != a;
    //@ assert ans != b;

    return ans;
}
