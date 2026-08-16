#include <stdbool.h>

/*@
    predicate strict_ascending(integer a, integer b, integer c, integer d, integer e) =
        a < b && b < c && c < d && d < e;
*/

/*@
    requires 0 <= a <= 123;
    requires 0 <= b <= 123;
    requires 0 <= c <= 123;
    requires 0 <= d <= 123;
    requires 0 <= e <= 123;
    requires 0 <= k <= 123;
    requires strict_ascending(a, b, c, d, e);
    ensures \result == (k <= e - a || k <= 0);
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long v[5];
    int n;
    
    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = d;
    v[4] = e;
    n = 5;
    
    if (k > e - a)
    {
        //@ assert k > e - a;
        return false;
    }
    else
    {
        //@ assert k <= e - a || k <= 0;
        return true;
    }
}
