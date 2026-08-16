#include <stdbool.h>
#include <stdint.h>

/*@
    requires (\valid((x) + (0..3)) &&
        1 <= (x)[0] <= 10000 &&
        1 <= (x)[1] <= 10000 &&
        1 <= (x)[2] <= 10000 &&
        1 <= (x)[3] <= 10000);
    ensures \result == ((x)[0] * (x)[1]) || \result == ((x)[2] * (x)[3]);
    ensures \result >= 1;
    assigns \nothing;
*/
int64_t func(int64_t* x)
{
    int64_t product1;
    int64_t product2;
    int64_t result;

    //@ assert 1 <= x[0] <= 10000;
    //@ assert 1 <= x[1] <= 10000;
    //@ assert 1 <= x[2] <= 10000;
    //@ assert 1 <= x[3] <= 10000;

    //@ assert 1 <= x[0] * x[1] <= 100000000;
    product1 = x[0] * x[1];

    //@ assert 1 <= x[2] * x[3] <= 100000000;
    product2 = x[2] * x[3];

    if (product1 > product2) {
        result = product1;
    } else {
        result = product2;
    }

    //@ assert result >= 1 && result <= 100000000;
    //@ assert result == product1 || result == product2;

    return result;
}
