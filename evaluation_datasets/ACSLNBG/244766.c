#include <stdbool.h>


bool func(long long a, long long b, long long c)
{
    bool ans;

    ans = (c >= a) && (c <= b);

    //@ assert ans == true <==> ((c) >= (a) && (c) <= (b));

    return ans;
}
