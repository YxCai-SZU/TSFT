#include <stdbool.h>
#include <limits.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires a == (long long)a;
    requires b == (long long)b;
    requires c == (long long)c;
    ensures \result == true <==> (b - a == c - b);
    assigns \nothing;
*/
bool func(long long a, long long b, long long c)
{
    long long diff1;
    long long diff2;
    bool result;

    diff1 = b - a;
    diff2 = c - b;

    //@ assert LLONG_MIN <= diff1 <= LLONG_MAX;
    //@ assert LLONG_MIN <= diff2 <= LLONG_MAX;
    //@ assert (diff1 == diff2) <==> (b - a == c - b);

    result = (diff1 == diff2);
    return result;
}
