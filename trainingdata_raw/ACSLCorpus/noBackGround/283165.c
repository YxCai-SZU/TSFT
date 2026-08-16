#include <stdbool.h>

/*@ requires 1 <= d <= 10000;
    requires 1 <= t <= 10000;
    requires 1 <= s <= 10000;
    ensures \result == (t * s >= d);
*/
bool func(long long d, long long t, long long s)
{
    //@ assert t * s <= 100000000;
    return t * s >= d;
}
