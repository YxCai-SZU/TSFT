#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= (b) <= 1000000000 &&
        -1000000000 <= (c) <= (d) <= 1000000000 &&
        (a) <= LONG_MAX && (a) >= LONG_MIN &&
        (b) <= LONG_MAX && (b) >= LONG_MIN &&
        (c) <= LONG_MAX && (c) >= LONG_MIN &&
        (d) <= LONG_MAX && (d) >= LONG_MIN);
    ensures \result == ((a) * (c)) || \result == ((b) * (c)) || 
            \result == ((a) * (d)) || \result == ((b) * (d));
    assigns \nothing;
*/
long func(long a, long b, long c, long d) {
    long f;
    long s;
    long t;
    
    //@ assert -1000000000000000000 <= a * c <= 1000000000000000000;
    //@ assert -1000000000000000000 <= b * c <= 1000000000000000000;
    //@ assert -1000000000000000000 <= a * d <= 1000000000000000000;
    //@ assert -1000000000000000000 <= b * d <= 1000000000000000000;
    
    if (a * c > b * c) {
        f = a * c;
    } else {
        f = b * c;
    }
    
    if (f > a * d) {
        s = f;
    } else {
        s = a * d;
    }
    
    if (s > b * d) {
        t = s;
    } else {
        t = b * d;
    }
    
    return t;
}
