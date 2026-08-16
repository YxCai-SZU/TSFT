#include <stdbool.h>

/*@
    requires ((a) > 0) && ((b) > 0) && ((c) > 0);
    requires (0 <= (a) <= 0xFFFFFFFF) && (0 <= (b) <= 0xFFFFFFFF) && (0 <= (c) <= 0xFFFFFFFF);
    ensures \result == ((a < b) && (b < c));
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert a > 0 && b > 0 && c > 0;
    //@ assert a <= 0xFFFFFFFF && b <= 0xFFFFFFFF && c <= 0xFFFFFFFF;
    
    result = (a < b) && (b < c);
    return result;
}
