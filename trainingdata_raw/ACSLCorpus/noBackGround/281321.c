#include <stdbool.h>

/*@
    requires -1000000000 <= a <= 1000000000;
    requires -1000000000 <= b <= 1000000000;
    requires -1000000000 <= c <= 1000000000;
    requires -1000000000 <= d <= 1000000000;
    requires a <= b;
    requires c <= d;
    ensures \result == (a <= d && c <= b);
*/
bool func(long a, long b, long c, long d)
{
    // Variable declarations at the top
    bool result;
    
    // Proof assertions
    //@ assert a <= b;
    //@ assert c <= d;
    
    result = (a <= d && c <= b);
    return result;
}
