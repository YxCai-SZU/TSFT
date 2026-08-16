#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    ensures \result == a * b || \result == c * d;
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    int sa;
    int sc;
    int res;
    
    //@ assert (1 <= (a) && (a) <= 10000);
    //@ assert (1 <= (b) && (b) <= 10000);
    //@ assert (1 <= (c) && (c) <= 10000);
    //@ assert (1 <= (d) && (d) <= 10000);
    
    //@ assert ((a) * (b)) <= 10000 * 10000;
    //@ assert ((c) * (d)) <= 10000 * 10000;
    
    //@ assert ((a) * (b)) >= 1;
    //@ assert ((c) * (d)) >= 1;
    
    sa = a * b;
    sc = c * d;
    
    if (sa > sc) {
        res = sa;
    } else {
        res = sc;
    }
    
    return res;
}
