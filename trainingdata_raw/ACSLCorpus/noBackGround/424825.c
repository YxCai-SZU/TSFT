#include <stdbool.h>

/*@
    requires (\valid((x) + (0..3)) &&
        (1 <= ((x)[0]) && ((x)[0]) <= 10000) &&
        (1 <= ((x)[1]) && ((x)[1]) <= 10000) &&
        (1 <= ((x)[2]) && ((x)[2]) <= 10000) &&
        (1 <= ((x)[3]) && ((x)[3]) <= 10000));
    ensures \result == ((x[0]) * (x[1])) || \result == ((x[2]) * (x[3]));
    ensures 1 <= \result;
*/
int func(int* x)
{
    int product1;
    int product2;
    int result;

    //@ assert (1 <= (x[0]) && (x[0]) <= 10000);
    //@ assert (1 <= (x[1]) && (x[1]) <= 10000);
    product1 = x[0] * x[1];

    //@ assert (1 <= (x[2]) && (x[2]) <= 10000);
    //@ assert (1 <= (x[3]) && (x[3]) <= 10000);
    product2 = x[2] * x[3];

    if (product1 > product2) {
        result = product1;
    } else {
        result = product2;
    }

    return result;
}
