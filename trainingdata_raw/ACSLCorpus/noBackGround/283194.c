#include <stdbool.h>

/*@
    requires 0 <= x <= 100000000000000000;
    requires 0 <= y <= 100000000000000000;
    ensures \result == (x == y);
    assigns \nothing;
*/
bool func(long long x, long long y)
{
    bool result;
    //@ assert x == y ==> x == y;
    result = (x == y);
    return result;
}
