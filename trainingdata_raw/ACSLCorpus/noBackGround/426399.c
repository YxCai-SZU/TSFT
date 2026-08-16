#include <stdint.h>

/*@
    requires \valid_read(v + (0..3));
    requires (-1000000000 <= (v[0]) <= 1000000000) && (-1000000000 <= (v[1]) <= 1000000000) && (-1000000000 <= (v[2]) <= 1000000000) && (-1000000000 <= (v[3]) <= 1000000000);
    ensures \result == v[0] * v[2] ||
            \result == v[0] * v[3] ||
            \result == v[1] * v[2] ||
            \result == v[1] * v[3];
    ensures \result == (\max(\max((v[0]) * (v[2]), (v[0]) * (v[3])), \max((v[1]) * (v[2]), (v[1]) * (v[3]))));
*/
int64_t func(const int64_t v[4])
{
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

    //@ assert (-1000000000 <= (a) <= 1000000000);
    //@ assert (-1000000000 <= (c) <= 1000000000);
    //@ assert (-1000000000000000000 <= (a) * (c) <= 1000000000000000000);
    max_val = a * c;

    //@ assert (-1000000000 <= (a) <= 1000000000);
    //@ assert (-1000000000 <= (d) <= 1000000000);
    //@ assert (-1000000000000000000 <= (a) * (d) <= 1000000000000000000);
    temp_val = a * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert (-1000000000 <= (b) <= 1000000000);
    //@ assert (-1000000000 <= (c) <= 1000000000);
    //@ assert (-1000000000000000000 <= (b) * (c) <= 1000000000000000000);
    temp_val = b * c;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert (-1000000000 <= (b) <= 1000000000);
    //@ assert (-1000000000 <= (d) <= 1000000000);
    //@ assert (-1000000000000000000 <= (b) * (d) <= 1000000000000000000);
    temp_val = b * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    return max_val;
}
