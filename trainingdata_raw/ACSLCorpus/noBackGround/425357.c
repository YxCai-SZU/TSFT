#include <stdbool.h>

/*@
    requires \valid(v + (0..3));
    requires (-1000000000 <= (v[0]) <= 1000000000) && (-1000000000 <= (v[1]) <= 1000000000) && (-1000000000 <= (v[2]) <= 1000000000) && (-1000000000 <= (v[3]) <= 1000000000);
    ensures \result == v[0] * v[2] || \result == v[0] * v[3] || 
            \result == v[1] * v[2] || \result == v[1] * v[3];
*/
long func(long v[4]) {
    long a;
    long b;
    long c;
    long d;
    long max1;
    long max2;
    long result;

    a = v[0];
    b = v[1];
    c = v[2];
    d = v[3];

    //@ assert (-1000000000 <= (a) <= 1000000000);
    //@ assert (-1000000000 <= (c) <= 1000000000);
    //@ assert (-1000000000 <= (d) <= 1000000000);
    //@ assert (-1000000000000000000 <= (a) * (c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (a) * (d) <= 1000000000000000000);

    if (a * c > a * d) {
        max1 = a * c;
    } else {
        max1 = a * d;
    }

    a = b;

    //@ assert (-1000000000 <= (a) <= 1000000000);
    //@ assert (-1000000000 <= (c) <= 1000000000);
    //@ assert (-1000000000 <= (d) <= 1000000000);
    //@ assert (-1000000000000000000 <= (a) * (c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (a) * (d) <= 1000000000000000000);

    if (a * c > a * d) {
        max2 = a * c;
    } else {
        max2 = a * d;
    }

    if (max1 > max2) {
        result = max1;
    } else {
        result = max2;
    }

    return result;
}
