#include <stdbool.h>

/*@
    requires ((4) == 4 &&
        \valid((v) + (0 .. 3)) &&
        (v)[0] >= 0 && (v)[0] <= 100 &&
        (v)[1] >= 0 && (v)[1] <= 100 &&
        (v)[2] >= 0 && (v)[2] <= 100 &&
        (v)[3] >= 0 && (v)[3] <= 100);
    ensures \result >= 0;
    ensures \result <= v[0] * v[3] + v[1] * v[2];
    assigns \nothing;
*/
int func(int *v)
{
    int a;
    int b;
    int result;

    //@ assert v[0] >= 0 && v[0] <= 100;
    //@ assert v[1] >= 0 && v[1] <= 100;
    //@ assert v[2] >= 0 && v[2] <= 100;
    //@ assert v[3] >= 0 && v[3] <= 100;

    //@ assert v[0] * v[3] <= 10000;
    //@ assert v[1] * v[2] <= 10000;

    a = v[0] * v[3];
    b = v[1] * v[2];

    if (a > b) {
        result = a;
    } else {
        result = b;
    }

    //@ assert result >= 0;
    //@ assert result <= v[0] * v[3] + v[1] * v[2];

    return result;
}
