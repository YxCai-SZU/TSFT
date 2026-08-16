#include <stdint.h>

/*@
    requires \valid(v + (0..3));
    requires ((4) == 4 &&
        1 <= (v)[0] <= 1000000000 &&
        1 <= (v)[1] <= 1000000000 &&
        1 <= (v)[2] <= 1000000000 &&
        1 <= (v)[3] <= 1000000000);
    ensures \result == v[0] * v[1] || \result == v[2] * v[3];
    ensures \result >= 1;
*/
int64_t func(int64_t* v) {
    int64_t a;
    int64_t b;
    int64_t c;
    int64_t d;
    int64_t max_val;
    int64_t temp_val;

    a = v[0];
    b = v[1];
    c = v[2];
    d = v[3];

    //@ assert 1 <= a <= 1000000000;
    //@ assert 1 <= b <= 1000000000;
    //@ assert 1 <= c <= 1000000000;
    //@ assert 1 <= d <= 1000000000;

    //@ assert a * b >= 1;
    //@ assert c * d >= 1;
    //@ assert a * b <= 1000000000000000000;
    //@ assert c * d <= 1000000000000000000;

    max_val = a * b;
    temp_val = c * d;

    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert max_val == a * b || max_val == c * d;
    //@ assert max_val >= 1;

    return max_val;
}
