#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (x) <= 100);
    ensures \result == true <==> ((a) <= (x) && (x) <= (a) + (b));
    assigns \nothing;
*/
bool func(long a, long b, long x)
{
    // Variable declarations at scope top
    bool result;

    //@ assert (0 <= (a) <= 100);
    
    if (x < a || a + b < x)
    {
        result = false;
    }
    else
    {
        // Critical verification property supporting postcondition
        //@ assert a <= x && x <= a + b;
        result = true;
    }

    //@ assert result == true <==> ((a) <= (x) && (x) <= (a) + (b));
    return result;
}
