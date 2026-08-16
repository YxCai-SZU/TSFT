#include <stdbool.h>

/*@
    requires 0 <= a <= 123;
    requires 0 <= b <= 123;
    requires 0 <= c <= 123;
    requires 0 <= d <= 123;
    requires 0 <= e <= 123;
    requires 0 <= k <= 123;
    requires a < b && b < c && c < d && d < e;
    ensures \result == true <==> (e - a <= k);
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long dist;
    //@ assert ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    //@ assert 0 <= e - a <= 123;
    dist = e - a;
    //@ assert dist == ((e) - (a));
    //@ assert 0 <= dist <= 123;
    if (dist <= k)
    {
        return true;
    }
    else
    {
        //@ assert dist > k;
        return false;
    }
}
