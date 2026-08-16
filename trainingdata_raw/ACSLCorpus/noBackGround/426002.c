#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100);
    requires (1 <= (y) <= 100);
    ensures \result == ((x) + (y)) || \result == ((x) * (y));
    assigns \nothing;
*/
int func(int x, int y) {
    int sum;
    int product;
    int ret;

    //@ assert (1 <= (x) <= 100);
    //@ assert (1 <= (y) <= 100);
    //@ assert ((x) * (y)) <= 10000;

    sum = x + y;
    product = x * y;

    if (sum > product) {
        ret = sum;
    } else {
        ret = product;
    }

    //@ assert ret == ((x) + (y)) || ret == ((x) * (y));
    return ret;
}
