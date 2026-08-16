#include <stddef.h>

/*@
    requires 0 <= n <= 100;
    requires 0 <= m <= 100;
    requires n + m >= 2;
    ensures \result == ((n) * ((n) - 1) / 2) + ((m) * ((m) - 1) / 2);
*/
size_t func(size_t n, size_t m) {
    size_t t;
    size_t u;
    size_t result;

    //@ assert n <= 100 && n >= 0;
    //@ assert ((n) * ((n) - 1) / 2) <= 4950;
    //@ assert m <= 100 && m >= 0;
    //@ assert ((m) * ((m) - 1) / 2) <= 4950;

    if (n > 0) {
        t = n * (n - 1) / 2;
        //@ assert t == ((n) * ((n) - 1) / 2);
    } else {
        t = 0;
        //@ assert t == ((n) * ((n) - 1) / 2);
    }

    if (m > 0) {
        u = m * (m - 1) / 2;
        //@ assert u == ((m) * ((m) - 1) / 2);
    } else {
        u = 0;
        //@ assert u == ((m) * ((m) - 1) / 2);
    }

    result = t + u;
    //@ assert result == ((n) * ((n) - 1) / 2) + ((m) * ((m) - 1) / 2);
    return result;
}
