#include <limits.h>

/*@
    requires (1 <= (a) <= 10000 && 1 <= (b) <= 10000) && (1 <= (c) <= 10000 && 1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b)) && \result >= ((c) * (d));
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long sa;
    long sc;
    long res;

    //@ assert (1 <= (a) <= 10000 && 1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000 && 1 <= (d) <= 10000);
    
    //@ assert ((a) * (b)) <= 100000000;
    //@ assert ((c) * (d)) <= 100000000;
    
    sa = a * b;
    sc = c * d;
    
    //@ assert sa == ((a) * (b));
    //@ assert sc == ((c) * (d));
    
    if (sa > sc) {
        res = sa;
        //@ assert res == ((a) * (b));
    } else {
        res = sc;
        //@ assert res == ((c) * (d));
    }
    
    //@ assert res >= ((a) * (b));
    //@ assert res >= ((c) * (d));
    
    return res;
}
