#include <stdbool.h>

/*@
    requires \valid(v + (0 .. 5));
    requires ((6) == 6 &&
    \forall integer i; 0 <= i < (6) ==> (((v)[i]) == 0 || ((v)[i]) == 1));
    ensures \result == (v[0] + v[1] + v[2] == v[3] + v[4] + v[5]);
*/
bool func(int *v) {
    int x0;
    int x1;
    int x2;
    int y0;
    int y1;
    int y2;
    int x_sum;
    int y_sum;
    bool result;

    x0 = v[0];
    x1 = v[1];
    x2 = v[2];
    y0 = v[3];
    y1 = v[4];
    y2 = v[5];
    x_sum = x0 + x1 + x2;
    y_sum = y0 + y1 + y2;

    //@ assert x_sum == v[0] + v[1] + v[2];
    //@ assert y_sum == v[3] + v[4] + v[5];

    result = (x_sum == y_sum);
    return result;
}
