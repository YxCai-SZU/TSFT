#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (x) && (x) <= 200);
    ensures \result == 1 <==> ((b) <= (x) && ((x) - (b)) <= (a));
    assigns \nothing;
*/
bool func(long a, long b, long x)
{
    bool result;

    if (b > x)
    {
        //@ assert b > x;
        result = false;
    }
    else if ((x - b) > a)
    {
        //@ assert (x - b) > a;
        result = false;
    }
    else
    {
        //@ assert b <= x && (x - b) <= a;
        result = true;
    }

    return result;
}
