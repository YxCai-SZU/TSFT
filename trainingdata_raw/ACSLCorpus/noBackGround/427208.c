#include <stdint.h>

/*@ requires (\valid((a)) && \valid((a)+1));
    requires a[0] <= 100 && a[1] <= 100;
    ensures \result <= a[1];
    ensures \result == ((a[0]) < (a[1]) ? (a[0]) : (a[1]));
*/
unsigned int func(unsigned int *a) {
    unsigned int n;
    unsigned int m;
    unsigned int result;

    n = a[0];
    m = a[1];

    if (n < m) {
        //@ assert n <= m;
        result = n;
    } else {
        //@ assert m <= n;
        result = m;
    }

    return result;
}
