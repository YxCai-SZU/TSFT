#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 123 &&
        1 <= (b) && (b) <= 123 &&
        1 <= (c) && (c) <= 123 &&
        1 <= (d) && (d) <= 123);
    ensures \result == 0 || \result == 1 || \result == 2 || \result == 3 || \result == 4;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    uint32_t s = 0;

    //@ assert (1 <= (a) && (a) <= 123 &&         1 <= (b) && (b) <= 123 &&         1 <= (c) && (c) <= 123 &&         1 <= (d) && (d) <= 123);

    if (a > b) { s += 1; }
    //@ assert 0 <= s <= 1;

    if (a > c) { s += 1; }
    //@ assert 0 <= s <= 2;

    if (a > d) { s += 1; }
    //@ assert 0 <= s <= 3;

    if (b > c) { s += 1; }
    //@ assert 0 <= s <= 4;

    if (b > d) { s += 1; }
    //@ assert 0 <= s <= 5;

    if (c > d) { s += 1; }
    //@ assert 0 <= s <= 6;

    int32_t ans;
    if (s == 0) {
        ans = 4;
    } else if (s == 1 || s == 2) {
        ans = 3;
    } else if (s == 3 || s == 4) {
        ans = 2;
    } else {
        ans = 1;
    }

    //@ assert ans == 0 || ans == 1 || ans == 2 || ans == 3 || ans == 4;
    return ans;
}
