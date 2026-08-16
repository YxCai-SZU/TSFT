#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= 1;
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long s1;
    long s2;
    long res;

    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    //@ assert ((a) * (b)) <= 10000 * 10000;
    
    //@ assert (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    //@ assert ((c) * (d)) <= 10000 * 10000;

    s1 = a * b;
    s2 = c * d;

    //@ assert s1 == ((a) * (b));
    //@ assert s2 == ((c) * (d));
    
    //@ assert 1 <= s1 <= 10000 * 10000;
    //@ assert 1 <= s2 <= 10000 * 10000;

    if (s1 >= s2) {
        res = s1;
    } else {
        res = s2;
    }

    //@ assert res == ((a) * (b)) || res == ((c) * (d));
    //@ assert res >= 1;
    
    return res;
}
