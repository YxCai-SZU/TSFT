#include <stdbool.h>

/*@
    requires 1 <= a <= 1000000000;
    requires 1 <= b <= 1000000000;
    requires 1 <= c <= 1000000000;
    ensures \result == true <==> ((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
*/
bool func(long long a, long long b, long long c)
{
    bool result = false;
    long long sum1 = 0;
    long long sum2 = 0;
    long long sum3 = 0;

    sum1 = a + b;
    sum2 = a + c;
    sum3 = b + c;

    if (sum1 == c)
    {
        result = true;
    }
    else if (sum2 == b)
    {
        result = true;
    }
    else if (sum3 == a)
    {
        result = true;
    }

    //@ assert result == true <==> ((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
    return result;
}
