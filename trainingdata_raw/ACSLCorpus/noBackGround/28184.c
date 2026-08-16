#include <stdint.h>

/*@
    requires \valid(v + (0..3));
    requires v[0] >= 1 && v[0] <= 1000000000;
    requires v[1] >= 1 && v[1] <= 1000000000;
    requires v[2] >= 1 && v[2] <= 1000000000;
    requires v[3] >= 1 && v[3] <= 1000000000;
    assigns \nothing;
    ensures \result == v[0] * v[1] || \result == v[2] * v[3];
    ensures \result >= 1;
*/
int64_t func(int64_t v[4])
{
    int64_t a;
    int64_t b;
    int64_t c;
    int64_t d;
    int64_t sa;
    int64_t sc;
    int64_t res;

    a = v[0];
    b = v[1];
    c = v[2];
    d = v[3];

    //@ assert ((a) >= 1 && (a) <= 1000000000 &&         (b) >= 1 && (b) <= 1000000000 &&         (c) >= 1 && (c) <= 1000000000 &&         (d) >= 1 && (d) <= 1000000000);

    //@ assert a * b <= 1000000000000000000;
    //@ assert c * d <= 1000000000000000000;

    sa = a * b;
    sc = c * d;

    //@ assert sa >= 1;
    //@ assert sc >= 1;

    if (sa > sc) {
        res = sa;
    } else {
        res = sc;
    }

    //@ assert res >= 1;
    return res;
}
