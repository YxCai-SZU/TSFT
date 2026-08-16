#include <stdbool.h>

/*@
    requires (1 <= (s) <= 100);
    requires (1 <= (w) <= 100);
    ensures \result == (s <= w);
*/
bool func(unsigned int s, unsigned int w)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= s <= 100;
    //@ assert 1 <= w <= 100;
    //@ assert s - w <= 0 ==> s - w <= 0;
    
    result = (s <= w);
    return result;
}
