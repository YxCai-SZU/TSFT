#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100);
    requires (1 <= (x) <= 100);
    ensures \result == (n >= x);
*/
bool func(int n, int x)
{
    // Variable declarations at scope top
    bool result;

    //@ assert (1 <= (n) <= 100);
    //@ assert (1 <= (x) <= 100);
    
    result = (n >= x);
    return result;
}
