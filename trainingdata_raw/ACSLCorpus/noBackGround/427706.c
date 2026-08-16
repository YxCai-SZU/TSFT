#include <limits.h>

/*@
    requires (-10000 <= (a) <= 10000) && (-10000 <= (b) <= 10000) && (-10000 <= (c) <= 10000) && (-10000 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((a) * (c)) || \result == ((a) * (d)) ||
            \result == ((b) * (c)) || \result == ((b) * (d)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b));
    ensures \result >= ((a) * (c));
    ensures \result >= ((a) * (d));
    ensures \result >= ((b) * (c));
    ensures \result >= ((b) * (d));
    ensures \result >= ((c) * (d));
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long max_ab;
    long max_ad;
    long max_bc;
    long max_cd;
    long max_ac;

    //@ assert (-10000 <= (a) <= 10000) && (-10000 <= (b) <= 10000) && (-10000 <= (c) <= 10000) && (-10000 <= (d) <= 10000);
    //@ assert -100000000 <= ((a) * (b)) <= 100000000;
    //@ assert -100000000 <= ((a) * (c)) <= 100000000;
    //@ assert -100000000 <= ((b) * (c)) <= 100000000;
    //@ assert -100000000 <= ((c) * (d)) <= 100000000;
    //@ assert -100000000 <= ((a) * (d)) <= 100000000;
    //@ assert -100000000 <= ((b) * (d)) <= 100000000;

    if (a * b > a * c)
        max_ab = a * b;
    else
        max_ab = a * c;

    if (a * d > b * c)
        max_ad = a * d;
    else
        max_ad = b * c;

    if (b * d > c * d)
        max_bc = b * d;
    else
        max_bc = c * d;

    if (max_ab > max_ad)
        max_cd = max_ab;
    else
        max_cd = max_ad;

    if (max_cd > max_bc)
        max_ac = max_cd;
    else
        max_ac = max_bc;

    return max_ac;
}
