#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    requires a <= b && c <= d;
    ensures \result == ((b) * (d)) || \result == ((b) * (c)) || 
            \result == ((a) * (d)) || \result == ((a) * (c));
*/
long long func(long long a, long long b, long long c, long long d)
{
    long long max1;
    long long max2;
    long long x;
    long long ac;
    long long ad;
    long long bc;
    long long bd;

    //@ assert (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    //@ assert a <= b && c <= d;

    ac = a * c;
    //@ assert -1000000000000000000 <= ac <= 1000000000000000000;

    ad = a * d;
    //@ assert -1000000000000000000 <= ad <= 1000000000000000000;

    bc = b * c;
    //@ assert -1000000000000000000 <= bc <= 1000000000000000000;

    bd = b * d;
    //@ assert -1000000000000000000 <= bd <= 1000000000000000000;

    if (ac > ad) {
        max1 = ac;
    } else {
        max1 = ad;
    }

    if (bc > bd) {
        max2 = bc;
    } else {
        max2 = bd;
    }

    if (max1 > max2) {
        x = max1;
    } else {
        x = max2;
    }

    //@ assert x == bd || x == bc || x == ad || x == ac;
    return x;
}
