#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100);
    requires (1 <= (b) && (b) <= 100);
    requires (1 <= (x) && (x) <= 100);
    ensures \result == (a <= x && x <= a + b);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x)
{
    // Variable declarations at top of scope
    bool result;

    if (a <= x && x <= a + b)
    {
        //@ assert a <= x && x <= a + b;
        result = true;
    }
    else
    {
        //@ assert !(a <= x && x <= a + b);
        result = false;
    }

    return result;
}
