#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (x) <= 100);
    ensures \result == (((a) <= (x) && (x) <= (a) + (b)) ? 1 : 0);
    assigns \nothing;
*/
bool func(long a, long b, long x)
{
    bool result;

    //@ assert (((a) <= (x) && (x) <= (a) + (b)) ? 1 : 0) == (((a) <= (x) && (x) <= (a) + (b)) ? 1 : 0);
    result = (a <= x) && (x <= a + b);
    return result;
}
