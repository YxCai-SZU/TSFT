#include <stdbool.h>

/*@
    requires ((a) > 0) && ((b) > 0) && ((c) > 0);
    ensures \result == ((a < b) && (b < c));
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    bool result;
    //@ assert ((a) > 0) && ((b) > 0) && ((c) > 0);
    if ((a < b) && (b < c))
    {
        result = true;
    }
    else
    {
        result = false;
    }
    //@ assert result == ((a < b) && (b < c));
    return result;
}

