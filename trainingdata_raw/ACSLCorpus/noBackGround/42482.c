#include <stdbool.h>

/*@
    requires (1 <= (s) <= 100);
    requires (1 <= (w) <= 100);
    ensures \result == (s > w);
    assigns \nothing;
*/
bool func(unsigned int s, unsigned int w)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert s <= 100;
    //@ assert s >= 1;
    //@ assert w <= 100;
    //@ assert w >= 1;
    //@ assert s > w ==> s > w;

    result = s > w;
    return result;
}
