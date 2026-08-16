#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    ensures \result == ((a) * (c)) || 
            \result == ((a) * (d)) || 
            \result == ((b) * (c)) || 
            \result == ((b) * (d)) || 
            \result == ((c) * (b));
    assigns \nothing;
*/
long long func(long long a, long long b, long long c, long long d)
{
    long long max1;
    long long max2;
    long long max;
    long long ac;
    long long ad;
    long long bd;
    long long cb;

    //@ assert (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    
    ac = a * c;
    //@ assert -1000000000000000000 <= ac <= 1000000000000000000;
    
    ad = a * d;
    //@ assert -1000000000000000000 <= ad <= 1000000000000000000;
    
    bd = b * d;
    //@ assert -1000000000000000000 <= bd <= 1000000000000000000;
    
    cb = c * b;
    //@ assert -1000000000000000000 <= cb <= 1000000000000000000;

    if (ac > ad) {
        max1 = ac;
    } else {
        max1 = ad;
    }
    //@ assert max1 == ((a) * (c)) || max1 == ((a) * (d));

    if (bd > cb) {
        max2 = bd;
    } else {
        max2 = cb;
    }
    //@ assert max2 == ((b) * (d)) || max2 == ((c) * (b));

    if (max1 > max2) {
        max = max1;
    } else {
        max = max2;
    }
    //@ assert max == ((a) * (c)) || max == ((a) * (d)) || max == ((b) * (c)) || max == ((b) * (d)) || max == ((c) * (b));

    return max;
}
