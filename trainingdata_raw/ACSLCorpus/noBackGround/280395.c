#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == a * b || \result == c * d;
    ensures \result >= a * b && \result >= c * d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int sa;
    int sc;
    int s;

    //@ assert a * b <= 10000 * 10000;
    //@ assert c * d <= 10000 * 10000;
    //@ assert a * b >= 1;
    //@ assert c * d >= 1;

    sa = a * b;
    sc = c * d;
    
    if (sa > sc) {
        s = sa;
    } else {
        s = sc;
    }

    //@ assert s == a * b || s == c * d;
    //@ assert s >= a * b;
    //@ assert s >= c * d;

    return s;
}
