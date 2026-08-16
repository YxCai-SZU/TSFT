#include <stdbool.h>

/*@
    requires 1 <= x <= 100000;
    ensures \result == true <==> (x >= 2000 && (x % 2000 == 0));
    assigns \nothing;
*/
bool func(unsigned long long x)
{
    bool result;

    //@ assert 1 <= x <= 100000;

    if (x >= 2000 && x % 2000 == 0)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == true <==> (x >= 2000 && (x % 2000 == 0));

    return result;
}
