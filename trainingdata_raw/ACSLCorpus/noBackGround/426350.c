#include <limits.h>

/*@
    requires (-10000 <= (a) <= 10000) && (-10000 <= (b) <= 10000) && (-10000 <= (c) <= 10000) && (-10000 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b));
    ensures \result >= ((c) * (d));
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long s1;
    long s2;
    long max_value;
    
    //@ assert (-10000 <= (a) <= 10000) && (-10000 <= (b) <= 10000);
    //@ assert -100000000 <= ((a) * (b)) <= 100000000;
    s1 = a * b;
    
    //@ assert (-10000 <= (c) <= 10000) && (-10000 <= (d) <= 10000);
    //@ assert -100000000 <= ((c) * (d)) <= 100000000;
    s2 = c * d;
    
    if (s1 > s2) {
        max_value = s1;
    } else {
        max_value = s2;
    }
    
    //@ assert max_value == ((a) * (b)) || max_value == ((c) * (d));
    //@ assert max_value >= ((a) * (b));
    //@ assert max_value >= ((c) * (d));
    
    return max_value;
}
