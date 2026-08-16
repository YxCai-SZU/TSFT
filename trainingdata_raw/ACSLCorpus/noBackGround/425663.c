#include <stdbool.h>

/*@
    requires 1 <= x <= 9;
    ensures \result == (x == 5 || x == 3 || x == 7);
    assigns \nothing;
 */
bool func(int x)
{
    bool result;
    //@ assert 1 <= x <= 9;

    if (x == 5 || x == 3 || x == 7)
    {
        //@ assert x == 5 || x == 3 || x == 7;
        result = true;
    }
    else
    {
        //@ assert x != 5 && x != 3 && x != 7;
        result = false;
    }

    //@ assert result == (x == 5 || x == 3 || x == 7);
    return result;
}
