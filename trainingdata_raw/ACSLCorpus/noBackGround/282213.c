#include <limits.h>

/*@
    requires ((x) != (y) &&
        (x) >= 1 && (x) <= 3 &&
        (y) >= 1 && (y) <= 3);
    ensures \result >= 1 && \result <= 3;
    ensures \result != x;
    ensures \result != y;
    assigns \nothing;
*/
int func(int x, int y)
{
    int ans;

    //@ assert x != y;
    //@ assert x >= 1 && x <= 3;
    //@ assert y >= 1 && y <= 3;
    
    //@ assert 6 - x - y >= 1;
    //@ assert 6 - x - y <= 3;
    //@ assert 6 - x - y != x;
    //@ assert 6 - x - y != y;

    ans = 6 - x - y;
    
    //@ assert ans >= 1 && ans <= 3;
    //@ assert ans != x;
    //@ assert ans != y;
    
    return ans;
}
