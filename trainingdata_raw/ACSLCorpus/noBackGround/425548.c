#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == ((a) * (c)) || \result == ((b) * (c)) || \result == ((c) * (d)) || \result == ((b) * (d));
    ensures \result >= ((a) * (c));
    ensures \result >= ((b) * (c));
    ensures \result >= ((c) * (d));
    ensures \result >= ((b) * (d));
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    // Variable declarations at scope top
    long max_value;
    long b_c;
    long c_d;
    long b_d;

    //@ assert (1 <= (a) <= 100) && (1 <= (c) <= 100);
    //@ assert 1 <= ((a) * (c)) <= 10000;
    max_value = a * c;

    //@ assert (1 <= (b) <= 100) && (1 <= (c) <= 100);
    //@ assert 1 <= ((b) * (c)) <= 10000;
    b_c = b * c;
    if (b_c > max_value) {
        max_value = b_c;
    }

    //@ assert (1 <= (c) <= 100) && (1 <= (d) <= 100);
    //@ assert 1 <= ((c) * (d)) <= 10000;
    c_d = c * d;
    if (c_d > max_value) {
        max_value = c_d;
    }

    //@ assert (1 <= (b) <= 100) && (1 <= (d) <= 100);
    //@ assert 1 <= ((b) * (d)) <= 10000;
    b_d = b * d;
    if (b_d > max_value) {
        max_value = b_d;
    }

    return max_value;
}
