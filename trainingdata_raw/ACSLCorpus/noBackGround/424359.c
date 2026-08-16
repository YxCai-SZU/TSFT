#include <stdbool.h>

/*@
    requires 0 <= a <= 123;
    requires 0 <= b <= 123;
    requires 0 <= c <= 123;
    requires 0 <= d <= 123;
    requires 0 <= e <= 123;
    requires 0 <= k <= 123;
    requires a < b;
    requires b < c;
    requires c < d;
    requires d < e;
    ensures \result == true <==> ((e) - (a) <= (k));
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long diff;
    bool result;

    diff = e - a;

    if (diff <= k)
    {
        result = true;
    }
    else
    {
        //@ assert diff > k;
        result = false;
    }

    return result;
}
