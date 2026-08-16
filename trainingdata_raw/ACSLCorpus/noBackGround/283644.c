#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b));
    ensures \result >= ((c) * (d));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    unsigned int sa, sb, sc, sd;
    unsigned int ab, cd;
    int ans;
    
    sa = (unsigned int)a;
    sb = (unsigned int)b;
    sc = (unsigned int)c;
    sd = (unsigned int)d;
    
    //@ assert (1 <= (sa) <= 10000);
    //@ assert (1 <= (sb) <= 10000);
    //@ assert (1 <= (sc) <= 10000);
    //@ assert (1 <= (sd) <= 10000);
    
    //@ assert ((sa) * (sb)) <= 10000 * 10000;
    ab = sa * sb;
    
    //@ assert ((sc) * (sd)) <= 10000 * 10000;
    cd = sc * sd;
    
    if (ab > cd) {
        ans = (int)ab;
    } else {
        ans = (int)cd;
    }
    
    //@ assert ans == ((a) * (b)) || ans == ((c) * (d));
    //@ assert ans >= ((a) * (b));
    //@ assert ans >= ((c) * (d));
    
    return ans;
}
