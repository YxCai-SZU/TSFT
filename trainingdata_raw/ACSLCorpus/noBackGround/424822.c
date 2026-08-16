#include <stdbool.h>

/*@
    requires 0 <= a <= 123;
    requires 0 <= b <= 123;
    requires 0 <= c <= 123;
    requires 0 <= d <= 123;
    requires 0 <= e <= 123;
    requires 0 <= k <= 123;
    requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == true <==> e - a <= k;
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    
    if (e - a > k) {
        //@ assert e - a > k;
        result = false;
    } else {
        //@ assert e - a <= k;
        result = true;
    }
    
    return result;
}
