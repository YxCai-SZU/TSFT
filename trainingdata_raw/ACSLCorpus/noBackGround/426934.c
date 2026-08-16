#include <stdbool.h>

/*@
  requires (1 <= (s) <= 100) && (1 <= (w) <= 100);
  ensures \result == (w >= s);
  assigns \nothing;
*/
bool func(int s, int w)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (1 <= (s) <= 100);
    //@ assert (1 <= (w) <= 100);
    //@ assert w >= 1;
    //@ assert s <= 100;

    result = (w >= s);
    return result;
}
