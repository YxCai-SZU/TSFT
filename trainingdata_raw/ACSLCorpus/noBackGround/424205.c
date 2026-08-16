#include <limits.h>

/*@
    requires (1 <= (x) <= 10000) && (1 <= (y) <= 10000) && (1 <= (z) <= 10000) && (1 <= (w) <= 10000);
    ensures \result == ((x) * (y)) || \result == ((z) * (w));
    ensures \result >= ((x) * (y));
    ensures \result >= ((z) * (w));
    assigns \nothing;
*/
int func(int x, int y, int z, int w)
{
    // Variable declarations at scope top
    int xy;
    int zw;
    int res;
    
    //@ assert (1 <= (x) <= 10000);
    //@ assert (1 <= (y) <= 10000);
    //@ assert (1 <= (z) <= 10000);
    //@ assert (1 <= (w) <= 10000);
    
    //@ assert ((x) * (y)) <= 100000000;
    xy = x * y;
    
    //@ assert ((z) * (w)) <= 100000000;
    zw = z * w;
    
    if (xy > zw) {
        res = xy;
    } else {
        res = zw;
    }
    
    //@ assert res == ((x) * (y)) || res == ((z) * (w));
    //@ assert res >= ((x) * (y));
    //@ assert res >= ((z) * (w));
    
    return res;
}
