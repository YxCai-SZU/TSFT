#include <stdbool.h>
/*@
    requires (\valid((x) + (0..3)) &&
        (x)[0] >= 1 && (x)[0] <= 10000 &&
        (x)[1] >= 1 && (x)[1] <= 10000 &&
        (x)[2] >= 1 && (x)[2] <= 10000 &&
        (x)[3] >= 1 && (x)[3] <= 10000);
    ensures \result == ((x)[0] * (x)[1]) || \result == ((x)[2] * (x)[3]);
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int* x)
{
    int product1;
    int product2;
    int res;

    //@ assert x[0] >= 1 && x[0] <= 10000;
    //@ assert x[1] >= 1 && x[1] <= 10000;
    //@ assert x[2] >= 1 && x[2] <= 10000;
    //@ assert x[3] >= 1 && x[3] <= 10000;

    //@ assert ((x)[0] * (x)[1]) >= 1 && ((x)[0] * (x)[1]) <= 100000000;
    //@ assert ((x)[2] * (x)[3]) >= 1 && ((x)[2] * (x)[3]) <= 100000000;

    product1 = x[0] * x[1];
    product2 = x[2] * x[3];

    if (product1 > product2) {
        res = product1;
    } else {
        res = product2;
    }

    //@ assert res == ((x)[0] * (x)[1]) || res == ((x)[2] * (x)[3]);
    //@ assert res >= 1;
    return res;
}
