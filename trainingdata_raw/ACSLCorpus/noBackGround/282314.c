#include <limits.h>

/*@
    requires (-10000 <= (a) <= 10000) && (-10000 <= (b) <= 10000) && (-10000 <= (c) <= 10000) && (-10000 <= (d) <= 10000);
    requires a <= b && c <= d;
    ensures \result == b * d || \result == b * c || \result == a * d || \result == a * c;
*/
int func(int a, int b, int c, int d)
{
    int max1;
    int max2;
    int res;

    //@ assert a >= -10000 && a <= 10000;
    //@ assert c >= -10000 && c <= 10000;

    //@ assert -1000000000 <= a * c <= 1000000000;
    //@ assert -1000000000 <= a * d <= 1000000000;

    if (a * c > a * d) {
        max1 = a * c;
    } else {
        max1 = a * d;
    }
    //@ assert max1 == a * c || max1 == a * d;

    //@ assert -1000000000 <= b * c <= 1000000000;
    //@ assert -1000000000 <= b * d <= 1000000000;

    if (b * c > b * d) {
        max2 = b * c;
    } else {
        max2 = b * d;
    }

    if (max1 > max2) {
        res = max1;
    } else {
        res = max2;
    }

    //@ assert res == b * d || res == b * c || res == a * d || res == a * c;
    return res;
}
