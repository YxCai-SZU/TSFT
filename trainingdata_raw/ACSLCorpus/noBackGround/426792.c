#include <stdbool.h>

/*@
    requires (\valid((v) + (0..5)) &&
        0 <= (v)[0] < 0x80000000 &&
        0 <= (v)[1] < 0x80000000 &&
        0 <= (v)[2] < 0x80000000 &&
        0 <= (v)[3] < 0x80000000 &&
        0 <= (v)[4] < 0x80000000 &&
        0 <= (v)[5] < 0x80000000 &&
        1 <= (v)[0] + (v)[1] + (v)[2] <= 0x7FFFFFFF &&
        1 <= (v)[3] + (v)[4] + (v)[5] <= 0x7FFFFFFF);
    ensures \result == (v[2] < v[5] && v[4] < v[1] && (v[0] + v[1] + v[2] < v[3] + v[4] + v[5]));
*/
bool func(int *v)
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    bool result;

    a = v[0];
    b = v[1];
    c = v[2];
    d = v[3];
    e = v[4];
    f = v[5];

    //@ assert 0 <= a + b + c <= 0x7FFFFFFF;
    //@ assert 0 <= d + e + f <= 0x7FFFFFFF;

    result = (c < f) && (e < b) && ((a + b + c) < (d + e + f));
    return result;
}
