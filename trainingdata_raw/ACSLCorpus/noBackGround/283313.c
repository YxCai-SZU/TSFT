#include <stdbool.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == true <==> ((a) <= 0 && (b) >= 0);
    assigns \nothing;
*/
bool func(int a, int b)
{
    // Variable declarations at top of scope
    bool result;

    if (a <= 0 && b >= 0)
    {
        result = true;
    }
    else
    {
        //@ assert a > 0 || b < 0;
        result = false;
    }

    return result;
}
