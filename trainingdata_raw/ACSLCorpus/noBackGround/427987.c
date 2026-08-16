#include <stddef.h>
#include <stdint.h>

/*@
    requires (\valid((a) + (0..3)) &&
        (1 <= ((a)[0]) <= 10000) &&
        (1 <= ((a)[1]) <= 10000) &&
        (1 <= ((a)[2]) <= 10000) &&
        (1 <= ((a)[3]) <= 10000));
    ensures \result == ((a[0]) * (a[1])) || \result == ((a[2]) * (a[3]));
    ensures \result >= ((a[0]) * (a[1]));
    ensures \result >= ((a[2]) * (a[3]));
    assigns \nothing;
*/
int64_t func(int64_t *a) {
    // Variable declarations at scope top
    int64_t prod1;
    int64_t prod2;
    int64_t result;

    //@ assert (1 <= (a[0]) <= 10000);
    //@ assert (1 <= (a[1]) <= 10000);
    //@ assert (1 <= (a[2]) <= 10000);
    //@ assert (1 <= (a[3]) <= 10000);

    //@ assert ((a[0]) * (a[1])) <= 100000000;
    //@ assert ((a[2]) * (a[3])) <= 100000000;

    prod1 = a[0] * a[1];
    prod2 = a[2] * a[3];

    if (prod1 > prod2) {
        result = prod1;
    } else {
        result = prod2;
    }

    return result;
}
