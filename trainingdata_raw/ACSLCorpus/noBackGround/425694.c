#include <stdbool.h>

/*@
    requires 1 <= l <= 1000;
    ensures \result == (l % 3 == 0 || l % 5 == 0 || l % 7 == 0);
    assigns \nothing;
*/
bool func(int l)
{
    // Variable declarations at the top
    bool result;

    if (l % 3 == 0 || l % 5 == 0 || l % 7 == 0)
    {
        //@ assert l % 3 == 0 || l % 5 == 0 || l % 7 == 0;
        result = true;
    }
    else
    {
        //@ assert l % 3 != 0 && l % 5 != 0 && l % 7 != 0;
        result = false;
    }

    return result;
}
