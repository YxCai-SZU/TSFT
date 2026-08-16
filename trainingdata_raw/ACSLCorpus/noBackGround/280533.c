#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    requires ((a) != (b) && (b) != (c) && (a) != (c));
    ensures \result == true <==> (((a) < (c) && (c) < (b)) || ((b) < (c) && (c) < (a)));
*/
bool func(long a, long b, long c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert ((a) != (b) && (b) != (c) && (a) != (c));

    result = (a < c && c < b) || (b < c && c < a);
    return result;
}
