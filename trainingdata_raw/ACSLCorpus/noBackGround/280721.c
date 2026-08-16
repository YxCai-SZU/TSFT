#include <stdint.h>

/*@ requires \valid(v + (0..3));
    requires 1 <= v[0] <= 10000;
    requires 1 <= v[1] <= 10000;
    requires 1 <= v[2] <= 10000;
    requires 1 <= v[3] <= 10000;
    ensures \result >= 0;
    ensures \result == v[0] * v[1] || \result == v[2] * v[3];
*/
int64_t func(int64_t* v) {
    int64_t a;
    int64_t b;
    int64_t c;
    int64_t d;
    int64_t max_val;

    a = v[0];
    b = v[1];
    c = v[2];
    d = v[3];

    //@ assert 1 <= a <= 10000 && 1 <= b <= 10000;
    //@ assert 0 <= a * b <= 10000 * 10000;
    max_val = a * b;

    //@ assert 1 <= c <= 10000 && 1 <= d <= 10000;
    //@ assert 0 <= c * d <= 10000 * 10000;
    if (c * d > max_val) {
        max_val = c * d;
    }

    //@ assert max_val >= 0;
    //@ assert max_val == v[0] * v[1] || max_val == v[2] * v[3];
    return max_val;
}
