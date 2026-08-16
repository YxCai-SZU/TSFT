#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) && (e) <= 123 &&
        0 <= (k) && (k) <= 123);
    ensures \result == (k >= (c - a) || k >= (d - b) || k >= (e - c));
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long diff1;
    long diff2;
    long diff3;
    bool result;

    //@ assert a < c && b < d && c < e;
    diff1 = c - a;
    //@ assert diff1 == (((a) > (c)) ? ((a) - (c)) : ((c) - (a)));
    
    diff2 = d - b;
    //@ assert diff2 == (((b) > (d)) ? ((b) - (d)) : ((d) - (b)));
    
    diff3 = e - c;
    //@ assert diff3 == (((c) > (e)) ? ((c) - (e)) : ((e) - (c)));

    if (k >= diff1 || k >= diff2 || k >= diff3) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
