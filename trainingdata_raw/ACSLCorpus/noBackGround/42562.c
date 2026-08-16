#include <limits.h>

/*@
    requires (-10000 <= (a) <= 10000) && (-10000 <= (b) <= 10000) && (-10000 <= (c) <= 10000) && (-10000 <= (d) <= 10000);
    requires a <= b && c <= d;
    ensures \result == ((b) * (d)) || \result == ((b) * (c)) || 
            \result == ((a) * (d)) || \result == ((a) * (c));
*/
long func(long a, long b, long c, long d)
{
    long max_val;
    long temp_val;

    //@ assert (-10000 <= (a) <= 10000) && (-10000 <= (c) <= 10000);
    //@ assert -100000000 <= ((a) * (c)) <= 100000000;
    max_val = a * c;

    //@ assert (-10000 <= (a) <= 10000) && (-10000 <= (d) <= 10000);
    //@ assert -100000000 <= ((a) * (d)) <= 100000000;
    temp_val = a * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert (-10000 <= (b) <= 10000) && (-10000 <= (c) <= 10000);
    //@ assert -100000000 <= ((b) * (c)) <= 100000000;
    temp_val = b * c;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert (-10000 <= (b) <= 10000) && (-10000 <= (d) <= 10000);
    //@ assert -100000000 <= ((b) * (d)) <= 100000000;
    temp_val = b * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    return max_val;
}
