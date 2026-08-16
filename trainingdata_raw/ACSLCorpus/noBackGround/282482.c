#include <stdbool.h>

/*@
    requires 1 <= n <= 100000;
    requires 1 <= k <= 100000;
    requires 1 <= a <= 100000;
    ensures \result == true <==> ((n) - (k) - (a) <= 0);
*/
bool func(long n, long k, long a)
{
    long diff;

    diff = n - k - a;
    if (diff <= 0)
    {
        //@ assert diff <= 0;
        return true;
    }
    else
    {
        //@ assert diff > 0;
        return false;
    }
}
