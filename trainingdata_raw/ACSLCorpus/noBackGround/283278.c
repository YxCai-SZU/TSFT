#include <stdbool.h>

/*@
    requires (1 <= (x) <= 205) && (1 <= (y) <= 205);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int x, int y) {
    int d;
    int t;
    int dx;
    int dy;
    int k;
    int result;
    
    d = (x > y) ? (x - y) : (y - x);
    
    if (x == 1 && y == 1) {
        t = 0;
    } else if (x == 1 || y == 1) {
        t = 1;
    } else {
        t = 2;
    }
    
    dx = (x - 1 < 0) ? -(x - 1) : (x - 1);
    dy = (y - 1 < 0) ? -(y - 1) : (y - 1);
    
    k = (dx > dy) ? dx : dy;
    
    //@ assert k >= 0;
    //@ assert d >= 0;
    //@ assert t >= 0;
    //@ assert k >= d || d >= k;
    
    result = (k >= d) ? (t + (k - d) * 2) : (t + (d - k));
    
    return result;
}
