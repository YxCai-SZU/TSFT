#include <stdbool.h>

/*@
    predicate bounds(integer v) = 1 <= v <= 100;
*/

/*@
    requires bounds(s);
    requires bounds(w);
    ensures \result == (s > w);
    assigns \nothing;
*/
bool func(int s, int w)
{
    // Variable declarations at top
    bool result;

    //@ assert bounds(s);
    //@ assert bounds(w);

    result = s > w;
    return result;
}
