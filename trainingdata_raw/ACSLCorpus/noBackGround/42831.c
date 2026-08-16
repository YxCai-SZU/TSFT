#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    requires a <= b && c <= d;
    ensures \result == a*c || \result == a*d || \result == b*c || \result == b*d;
    assigns \nothing;
*/
long long func(long long a, long long b, long long c, long long d) {
    long long res;
    int i;

    //@ assert (-1000000000000000000 <= (a) * (c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (a) * (d) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (b) * (c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (b) * (d) <= 1000000000000000000);

    res = a * c;
    i = 0;

    /*@
        loop invariant 0 <= i <= 4;
        loop invariant res == a*c || res == a*d || res == b*c || res == b*d;
        loop invariant (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
        loop invariant a <= b && c <= d;
        loop assigns i, res;
        loop variant 4 - i;
    */
    while (i < 4) {
        if (i == 0) {
            res = (res > a * c) ? res : a * c;
        } else if (i == 1) {
            res = (res > a * d) ? res : a * d;
        } else if (i == 2) {
            res = (res > b * c) ? res : b * c;
        } else if (i == 3) {
            res = (res > b * d) ? res : b * d;
        }
        i++;
    }

    return res;
}
