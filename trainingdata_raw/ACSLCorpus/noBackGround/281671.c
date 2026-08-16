#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    requires x == (long long)x;
    requires y == (long long)y;
    ensures \result == ((y - 2 * x) >= 0 && (y - 2 * x) <= x);
*/
bool func(long long x, long long y)
{
    long long diff;
    diff = y - 2 * x;
    //@ assert diff == y - 2 * x;
    return diff >= 0 && diff <= x;
}
