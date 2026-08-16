#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 && 1 <= (b) && (b) <= 100);
    ensures \result == 1 <==> (((a) * 2 < (b)) || ((b) * 2 < (a)));
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    bool result;

    //@ assert a * 2 <= 200;
    //@ assert b * 2 <= 200;

    if (a * 2 < b || b * 2 < a)
    {
        //@ assert (((a) * 2 < (b)) || ((b) * 2 < (a)));
        result = true;
    }
    else
    {
        //@ assert !(((a) * 2 < (b)) || ((b) * 2 < (a)));
        result = false;
    }

    return result;
}
