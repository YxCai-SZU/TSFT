#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100);
    requires (1 <= (y) <= 100);
    ensures \result == (x * 3 <= y * 2);
    assigns \nothing;
*/
bool func(unsigned long long x, unsigned long long y)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert x * 3 <= y * 2 ==> x * 3 <= y * 2;

    result = (x * 3 <= y * 2);
    return result;
}
