#include <stdbool.h>

/*@
    requires \valid(v + (0..1));
    requires 1 <= v[0] && v[0] <= 100;
    requires 1 <= v[1] && v[1] <= 100;
    ensures \result == (v[0] <= v[1] * 2 || v[1] <= v[0] * 2);
*/
bool func(int v[2]) {
    int w;
    int h;
    bool result;
    
    w = v[0];
    h = v[1];
    
    //@ assert (1 <= (w) && (w) <= 100);
    //@ assert (1 <= (h) && (h) <= 100);
    
    if (w <= h * 2 || h <= w * 2) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == ((((w) <= (h) * 2) ? 1 : ((h) <= (w) * 2 ? 1 : 0)) == 1);
    return result;
}
