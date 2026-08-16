#include <stdint.h>
#include <stdbool.h>

/*@
    requires (\valid((input) + (0..4)));
    ensures \result <= 0xffffffffffffffff;
    assigns \nothing;
*/
uint64_t func(uint64_t input[5])
{
    uint64_t a;
    uint64_t b;
    uint64_t x;
    uint64_t c;
    uint64_t d;
    uint64_t diff1;
    uint64_t diff2;
    uint64_t ans;

    a = input[0];
    b = input[1];
    x = input[2];
    c = input[3];
    d = input[4];

    //@ assert a <= 0xffffffffffffffff && x <= 0xffffffffffffffff;
    if (x < a) {
        diff1 = a - x;
    } else {
        diff1 = x - a;
    }

    //@ assert c <= 0xffffffffffffffff && d <= 0xffffffffffffffff;
    if (c < d) {
        diff2 = d - c;
    } else {
        diff2 = c - d;
    }

    //@ assert diff1 <= 0xffffffffffffffff && diff2 <= 0xffffffffffffffff;
    if (diff1 > diff2) {
        ans = diff1;
    } else {
        ans = diff2;
    }

    //@ assert ans <= 0xffffffffffffffff;
    return ans;
}
