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
long func(long *x) {
    long product1;
    long product2;
    long max_value;

    //@ assert x[0] >= 1 && x[0] <= 10000;
    product1 = x[0] * x[1];

    //@ assert x[2] >= 1 && x[2] <= 10000;
    product2 = x[2] * x[3];

    if (product1 > product2) {
        max_value = product1;
    } else {
        max_value = product2;
    }

    //@ assert max_value >= 1;
    return max_value;
}
