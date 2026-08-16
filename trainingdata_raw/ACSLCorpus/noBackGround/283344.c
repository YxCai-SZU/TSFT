#include <stdbool.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures ((\result) == ((a) <= 0 && 0 <= (b)));
    assigns \nothing;
*/
bool func(long a, long b)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    //@ assert (a <= 0 && 0 <= b) ==> (a <= 0 && 0 <= b);

    result = (a <= 0 && 0 <= b);
    return result;
}
