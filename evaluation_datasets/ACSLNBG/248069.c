#include <stdint.h>

uint64_t func(uint64_t x) {
    uint64_t quotient;
    uint64_t remainder;
    uint64_t ans;

    quotient = x / 11;
    remainder = x % 11;
    ans = quotient * 2;

    //@ assert ans == (((x) / 11) * 2);
    //@ assert ans <= (((x) / 11) * 2 + 2);

    if (remainder > 0 && remainder <= 6) {
        ans += 1;
        //@ assert ans == (((x) / 11) * 2) + 1;
    } else if (remainder > 6) {
        ans += 2;
        //@ assert ans == (((x) / 11) * 2) + 2;
    }

    //@ assert ans >= (((x) / 11) * 2);
    //@ assert ans <= (((x) / 11) * 2 + 2);
    return ans;
}
