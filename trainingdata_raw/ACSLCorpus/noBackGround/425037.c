#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b)) && \result >= ((c) * (d));
    assigns \nothing;
*/
int func(int a, int b, int c, int d) {
    int sa;
    int sc;
    int res;
    
    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    
    //@ assert ((a) * (b)) <= 10000 * 10000;
    sa = a * b;
    
    //@ assert ((c) * (d)) <= 10000 * 10000;
    sc = c * d;
    
    //@ assert sa == ((a) * (b));
    //@ assert sc == ((c) * (d));
    
    if (sa > sc) {
        res = sa;
    } else {
        res = sc;
    }
    
    //@ assert res == ((a) * (b)) || res == ((c) * (d));
    return res;
}
