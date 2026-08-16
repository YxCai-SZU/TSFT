#include <stdbool.h>

/*@
    requires (0 <= (a) < 124 &&
        0 <= (b) < 124 &&
        0 <= (c) < 124 &&
        0 <= (d) < 124 &&
        0 <= (e) < 124 &&
        0 <= (k) <= 124);
    ensures \result == (a + k >= b && b + k >= c && c + k >= d && d + k >= e);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int k)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 0 <= a < 124 && 0 <= k <= 124;
    //@ assert 0 <= a + k <= 248;
    
    //@ assert 0 <= b < 124 && 0 <= k <= 124;
    //@ assert 0 <= b + k <= 248;
    
    //@ assert 0 <= c < 124 && 0 <= k <= 124;
    //@ assert 0 <= c + k <= 248;
    
    //@ assert 0 <= d < 124 && 0 <= k <= 124;
    //@ assert 0 <= d + k <= 248;
    
    result = (a + k >= b) && (b + k >= c) && (c + k >= d) && (d + k >= e);
    return result;
}
