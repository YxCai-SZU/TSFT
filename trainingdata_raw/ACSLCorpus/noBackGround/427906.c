#include <stdbool.h>

/*@
    requires (1 <= (x) && (x) <= 16 && 1 <= (y) && (y) <= 16 && (x) + (y) <= 16);
    ensures \result == (x <= 8 && y <= 8);
    assigns \nothing;
*/
bool func(long x, long y)
{
    long m = 8;
    long n = 8;
    bool result;
    
    //@ assert (1 <= (x) && (x) <= 16 && 1 <= (y) && (y) <= 16 && (x) + (y) <= 16);
    
    if (x <= m && y <= n) {
        result = true;
    } else {
        //@ assert x > m || y > n;
        result = false;
    }
    
    //@ assert result == (x <= 8 && y <= 8);
    return result;
}
