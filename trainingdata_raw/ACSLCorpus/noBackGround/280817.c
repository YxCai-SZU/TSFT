#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100000000000 &&
        0 <= (a) && (a) < (b) && (b) < (n));
    ensures \result == ((b - a - 1) < (n - b));
*/
bool func(long long n, long long a, long long b)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= n && n <= 100000000000;
    //@ assert 0 <= a && a < b && b < n;
    
    result = (b - a - 1) < (n - b);
    return result;
}
