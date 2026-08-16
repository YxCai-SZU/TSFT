#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (x) && (x) <= 200);
    ensures \result == (a <= x && a + b >= x);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert ((a) + (b) <= 200);
    //@ assert (1 <= (x) && (x) <= 200);

    result = (a <= x) && (a + b >= x);
    return result;
}
