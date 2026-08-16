#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (x) <= 200);
    ensures ((\result) == ((x) >= (a) && (x) <= (a) + (b)));
    assigns \nothing;
*/
bool func(long a, long b, long x)
{
    long left;
    long right;
    bool result;

    //@ assert (1 <= (a) <= 100 &&         1 <= (b) <= 100 &&         1 <= (x) <= 200);
    left = x - a;
    if (left < 0)
    {
        result = false;
        //@ assert ((result) == ((x) >= (a) && (x) <= (a) + (b)));
        return result;
    }
    right = a + b - x;
    if (right < 0)
    {
        result = false;
        //@ assert ((result) == ((x) >= (a) && (x) <= (a) + (b)));
        return result;
    }
    result = true;
    //@ assert ((result) == ((x) >= (a) && (x) <= (a) + (b)));
    return result;
}
