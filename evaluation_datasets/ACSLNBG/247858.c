#include <limits.h>


long func(long r, long g, long b) {
    long m;
    long l;
    long ans;

    //@ assert (1 <= (r) && (r) <= 100 &&         1 <= (g) && (g) <= 100 &&         1 <= (b) && (b) <= 100 &&         (r) + (g) + (b) >= 2);
    
    if (r > g) {
        if (r > b) {
            m = r;
        } else {
            m = b;
        }
    } else {
        if (g > b) {
            m = g;
        } else {
            m = b;
        }
    }
    
    //@ assert m == (((r) > (g)) ? (((r) > (b)) ? (r) : (b)) : (((g) > (b)) ? (g) : (b)));
    
    l = 3 * m - (r + g + b);
    
    //@ assert l == (3 * ((((r)) > ((g))) ? ((((r)) > ((b))) ? ((r)) : ((b))) : ((((g)) > ((b))) ? ((g)) : ((b)))) - ((r) + (g) + (b)));
    
    ans = l;
    
    if (l < 0) {
        ans = 0;
        //@ assert ans == 0;
    } else {
        //@ assert ans == l;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= 2 * r + 2 * g + 2 * b - 3;
    
    return ans;
}
