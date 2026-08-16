#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    requires a <= b && c <= d;
    requires a <= INT_MAX && a >= INT_MIN;
    requires b <= INT_MAX && b >= INT_MIN;
    requires c <= INT_MAX && c >= INT_MIN;
    requires d <= INT_MAX && d >= INT_MIN;
    ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d;
*/
long long func(long long a, long long b, long long c, long long d)
{
    long long max_val;
    long long new_val;

    //@ assert (-1000000000000000000 <= (a * c) <= 1000000000000000000);
    max_val = a * c;

    //@ assert (-1000000000000000000 <= (b * c) <= 1000000000000000000);
    new_val = b * c;
    if (new_val > max_val)
    {
        max_val = new_val;
    }

    //@ assert (-1000000000000000000 <= (a * d) <= 1000000000000000000);
    new_val = a * d;
    if (new_val > max_val)
    {
        max_val = new_val;
    }

    //@ assert (-1000000000000000000 <= (b * d) <= 1000000000000000000);
    new_val = b * d;
    if (new_val > max_val)
    {
        max_val = new_val;
    }

    return max_val;
}
