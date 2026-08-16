#include <stdbool.h>

/*@
    requires \valid(v + (0..5));
    requires (1 <= (v[0]) <= 1000000000 &&
        1 <= (v[1]) <= 1000000000 &&
        1 <= (v[2]) <= 1000000000 &&
        1 <= (v[3]) <= 1000000000 &&
        1 <= (v[4]) <= 1000000000 &&
        1 <= (v[5]) <= 1000000000);
    assigns \nothing;
    ensures \result == true <==> ((v[4]) >= (v[0]) && (v[5]) >= (v[1]) && (v[4]) - (v[0]) <= (v[2]) && (v[5]) - (v[1]) <= (v[3]));
*/
bool func(const unsigned long v[6]) {
    unsigned long s0;
    unsigned long s1;
    unsigned long k0;
    unsigned long k1;
    unsigned long x;
    unsigned long y;
    bool result;

    s0 = v[0];
    s1 = v[1];
    k0 = v[2];
    k1 = v[3];
    x = v[4];
    y = v[5];

    //@ assert (1 <= (s0) <= 1000000000 &&         1 <= (s1) <= 1000000000 &&         1 <= (k0) <= 1000000000 &&         1 <= (k1) <= 1000000000 &&         1 <= (x) <= 1000000000 &&         1 <= (y) <= 1000000000);

    if (x < s0 || y < s1 || x - s0 > k0 || y - s1 > k1) {
        result = false;
    } else {
        result = true;
    }

    //@ assert result == true <==> ((x) >= (s0) && (y) >= (s1) && (x) - (s0) <= (k0) && (y) - (s1) <= (k1));
    return result;
}
