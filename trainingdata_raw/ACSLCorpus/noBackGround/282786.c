#include <limits.h>

/*@
    requires (-10000 <= (a) <= 10000) && (-10000 <= (b) <= 10000) && (-10000 <= (c) <= 10000) && (-10000 <= (d) <= 10000);
    ensures \result == ((a) * (c)) || \result == ((a) * (d)) ||
            \result == ((b) * (c)) || \result == ((b) * (d));
*/
int func(int a, int b, int c, int d)
{
    int max1;
    int max2;
    int res;

    //@ assert (-10000 <= (a) <= 10000) && (-10000 <= (c) <= 10000);
    //@ assert -100000000 <= ((a) * (c)) <= 100000000;

    //@ assert (-10000 <= (a) <= 10000) && (-10000 <= (d) <= 10000);
    //@ assert -100000000 <= ((a) * (d)) <= 100000000;

    if (a * c > a * d)
        max1 = a * c;
    else
        max1 = a * d;

    //@ assert (-10000 <= (b) <= 10000) && (-10000 <= (c) <= 10000);
    //@ assert -100000000 <= ((b) * (c)) <= 100000000;

    //@ assert (-10000 <= (b) <= 10000) && (-10000 <= (d) <= 10000);
    //@ assert -100000000 <= ((b) * (d)) <= 100000000;

    if (b * c > b * d)
        max2 = b * c;
    else
        max2 = b * d;

    if (max1 > max2)
        res = max1;
    else
        res = max2;

    return res;
}
