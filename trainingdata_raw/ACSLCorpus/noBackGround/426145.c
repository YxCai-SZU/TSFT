#include <stdbool.h>

/*@
    requires (\valid((v)) && \valid((v)+1) && \valid((v)+2) && \valid((v)+3) &&
        (v)[0] >= 1 && (v)[0] <= 10000 &&
        (v)[1] >= 1 && (v)[1] <= 10000 &&
        (v)[2] >= 1 && (v)[2] <= 10000 &&
        (v)[3] >= 1 && (v)[3] <= 10000);
    ensures \result >= 0;
    ensures \result <= v[0] * v[1] || \result <= v[2] * v[3];
*/
int func(int *v)
{
    int a;
    int b;
    int c;
    int d;
    int max1;
    int abs_val;
    int tmp;

    a = v[0];
    b = v[1];
    c = v[2];
    d = v[3];

    //@ assert a >= 1 && a <= 10000;
    //@ assert b >= 1 && b <= 10000;
    //@ assert c >= 1 && c <= 10000;
    //@ assert d >= 1 && d <= 10000;

    //@ assert a * b >= 0;
    //@ assert c * d >= 0;
    //@ assert a * b <= 10000 * 10000;
    //@ assert c * d <= 10000 * 10000;

    if (a * b > c * d) {
        max1 = a * b;
    } else {
        max1 = c * d;
    }

    tmp = max1 - (a * b);
    if (tmp < 0) {
        abs_val = -tmp;
    } else {
        abs_val = tmp;
    }

    //@ assert abs_val >= 0;
    //@ assert abs_val <= a * b || abs_val <= c * d;

    return abs_val;
}
