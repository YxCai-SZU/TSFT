#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == a*b || \result == c*d;
    ensures \result >= a*b && \result >= c*d;
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long sa;
    long sc;
    long res;

    //@ assert 1 <= a*b <= LONG_MAX;
    //@ assert 1 <= c*d <= LONG_MAX;
    
    sa = a * b;
    sc = c * d;
    
    //@ assert sa >= 1 && sa <= LONG_MAX;
    //@ assert sc >= 1 && sc <= LONG_MAX;
    
    if (sa > sc) {
        res = sa;
    } else {
        res = sc;
    }
    
    //@ assert res == sa || res == sc;
    return res;
}
