#include <stdbool.h>

/*@
    requires (1 <= (s) <= 100) && (1 <= (w) <= 100);
    ensures ((\result) == ((s) <= (w)));
    assigns \nothing;
*/
bool func(unsigned long s, unsigned long w)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert s <= 100;
    //@ assert w >= 1;
    //@ assert s <= w || s > w;

    result = s <= w;
    return result;
}
