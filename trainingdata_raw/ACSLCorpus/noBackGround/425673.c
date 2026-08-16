#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    requires a <= b && c <= d;
    ensures \result == b * d || \result == a * d || \result == b * c || \result == a * c;
*/
long long func(long long a, long long b, long long c, long long d)
{
    long long m;
    long long temp_m;

    //@ assert (-1000000000000000000 <= (a) * (c) <= 1000000000000000000);
    m = a * c;

    //@ assert (-1000000000000000000 <= (a) * (d) <= 1000000000000000000);
    temp_m = a * d;
    if (temp_m > m) {
        m = temp_m;
    }

    //@ assert (-1000000000000000000 <= (b) * (c) <= 1000000000000000000);
    temp_m = b * c;
    if (temp_m > m) {
        m = temp_m;
    }

    //@ assert (-1000000000000000000 <= (b) * (d) <= 1000000000000000000);
    temp_m = b * d;
    if (temp_m > m) {
        m = temp_m;
    }

    return m;
}
