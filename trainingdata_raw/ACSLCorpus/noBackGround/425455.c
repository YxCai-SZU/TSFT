#include <stdbool.h>

/*@
    requires (1 <= (s) <= 100);
    requires (1 <= (w) <= 100);
    ensures \result == (w >= s);
*/
bool func(unsigned int s, unsigned int w)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= s <= 100;
    //@ assert 1 <= w <= 100;
    
    result = (w >= s);
    return result;
}
