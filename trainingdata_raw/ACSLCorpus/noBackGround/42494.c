#include <stdbool.h>

/*@
    requires ((0 <= ((a)) <= 100) && (0 <= ((b)) <= 100) && (0 <= ((x)) <= 100));
    ensures ((\result) == ((b) <= (x) && (x) <= (a) + (b)));
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long x)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (x) <= 100);

    if (b > x)
    {
        //@ assert b > x;
        //@ assert x < a + b;
        result = false;
    }
    else if (x <= a + b)
    {
        //@ assert x <= a + b;
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert ((result) == ((b) <= (x) && (x) <= (a) + (b)));
    return result;
}
