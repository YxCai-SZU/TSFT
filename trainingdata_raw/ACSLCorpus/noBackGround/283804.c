#include <stdbool.h>

/*@
    requires w >= 0 && h >= 0;
    requires 0 <= x && x <= w;
    requires 0 <= y && y <= h;
    requires r >= 0;
    ensures \result == true <==> ((r) <= (y) && (y) <= (h) - (r) && (r) <= (x) && (x) <= (w) - (r));
*/
bool func(long w, long h, long x, long y, long r)
{
    bool res = false;
    //@ assert w >= 0 && h >= 0 && 0 <= x && x <= w && 0 <= y && y <= h && r >= 0;
    
    if (r <= y && y <= (h - r) && r <= x && x <= (w - r))
    {
        res = true;
    }
    
    //@ assert res == true <==> ((r) <= (y) && (y) <= (h) - (r) && (r) <= (x) && (x) <= (w) - (r));
    return res;
}
