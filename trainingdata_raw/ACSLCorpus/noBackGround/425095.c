#include <stdbool.h>

/*@
    requires 1 <= x && x <= 16;
    requires 1 <= y && y <= 16;
    requires x + y <= 16;
    ensures \result == (x <= 8 || y <= 8);
*/
bool func(int x, int y)
{
    int max_val;
    
    if (x > y) {
        max_val = x;
        //@ assert (((x) > (y) && (max_val) == (x)) || ((x) <= (y) && (max_val) == (y)));
    } else {
        max_val = y;
        //@ assert (((x) > (y) && (max_val) == (x)) || ((x) <= (y) && (max_val) == (y)));
    }
    
    //@ assert max_val == x || max_val == y;
    
    return (x <= 8) || (y <= 8);
}
