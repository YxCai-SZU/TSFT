#include <stdbool.h>

/*@
    requires (2 <= (n) <= 100 && 1 <= (a) < (b) <= (n));
    ensures ((\result) == ((b) - (a) == 1 || ((a) + 1 < (b) && (b) - (a) == 2)));
    assigns \nothing;
*/
bool func(int n, int a, int b)
{
    // Variable declarations at top of scope
    bool result;

    if (b - a == 1)
    {
        result = true;
    }
    else if (a + 1 < b && b - a == 2)
    {
        result = true;
    }
    else
    {
        //@ assert b - a != 1 && !(a + 1 < b && b - a == 2);
        result = false;
    }

    return result;
}
