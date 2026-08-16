#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires a != b;
    ensures \result == true <==> (((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    bool result;

    //@ assert a != b;

    if (a < b)
    {
        if (b < c)
        {
            result = true;
            //@ assert (((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
        }
        else
        {
            result = false;
            //@ assert !(((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
        }
    }
    else
    {
        if (a > b)
        {
            if (b > c)
            {
                result = true;
                //@ assert (((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
            }
            else
            {
                result = false;
                //@ assert !(((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
            }
        }
        else
        {
            result = false;
            //@ assert !(((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
        }
    }

    return result;
}
