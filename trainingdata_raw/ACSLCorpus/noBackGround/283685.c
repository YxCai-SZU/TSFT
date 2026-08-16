#include <limits.h>

/*@
    requires (-273 <= (x) && (x) <= 100);
    ensures \result == ((x) < 30 ? 30 - (x) : (x) - 30);
    assigns \nothing;
*/
int func(int x)
{
    int result;

    if (x < 30)
    {
        //@ assert x < 30;
        result = 30 - x;
    }
    else
    {
        //@ assert x >= 30;
        result = x - 30;
    }

    return result;
}
