#include <stdbool.h>

/*@
    requires -1000000000 <= a <= 1000000000;
    requires -1000000000 <= b <= 1000000000;
    requires -1000000000 <= c <= 1000000000;
    requires -1000000000 <= d <= 1000000000;
    requires a <= b;
    requires c <= d;
    ensures \result == true <==> (a <= d && c <= b);
 */
bool func(long a, long b, long c, long d)
{
    bool result;

    result = false;

    if (a <= d && c <= b)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == true <==> (a <= d && c <= b);

    return result;
}
