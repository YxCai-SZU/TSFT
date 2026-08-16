#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (x) && (x) <= 200);
    ensures \result == ((((a) <= (x) && (a) + (b) >= (x)) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    unsigned int remaining;
    bool result;

    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1 <= (x) && (x) <= 200);

    if (x < a)
    {
        result = false;
    }
    else
    {
        remaining = x - a;
        if (remaining > b)
        {
            result = false;
        }
        else
        {
            //@ assert remaining <= b;
            result = true;
        }
    }

    //@ assert result == ((((a) <= (x) && (a) + (b) >= (x)) ? 1 : 0) == 1);
    return result;
}
