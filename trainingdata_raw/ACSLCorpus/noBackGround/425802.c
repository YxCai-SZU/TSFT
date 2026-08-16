#include <stdbool.h>

/*@
    requires (1 <= (a) <= 500);
    requires (1 <= (b) <= 500);
    requires (1 <= (c) <= 1000);
    ensures \result == (a + b >= c);
*/
bool func(long a, long b, long c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= a <= 500;
    //@ assert 1 <= b <= 500;
    //@ assert 1 <= c <= 1000;

    result = (a + b >= c);
    return result;
}
