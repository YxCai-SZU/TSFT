#include <stdbool.h>

/*@
    requires (1 <= (s) <= 100);
    requires (1 <= (w) <= 100);
    ensures \result == (s <= w);
*/
bool func(int s, int w)
{
    //@ assert (1 <= (s) <= 100);
    //@ assert (1 <= (w) <= 100);
    return s <= w;
}
