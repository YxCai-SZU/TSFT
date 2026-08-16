#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == true <==> ((x) >= 2000 ||
        (100 * (((x)) / 100) <= (x) && (x) <= 105 * (((x)) / 100)));
    assigns \nothing;
*/
bool func(unsigned int x)
{
    unsigned int n;
    unsigned int mo;
    bool result;

    n = x / 100;
    mo = x % 100;

    if (x >= 2000)
    {
        result = true;
    }
    else
    {
        //@ assert n <= 1000;
        //@ assert mo <= 100;
        //@ assert 100 * n <= 100000;
        //@ assert 105 * n <= 105000;

        if (100 * n <= x && x <= 105 * n)
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }

    return result;
}
