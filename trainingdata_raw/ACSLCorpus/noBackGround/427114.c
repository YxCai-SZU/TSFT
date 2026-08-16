#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(int n, int m)
{
    // Variable declarations at scope top
    int diff;
    bool result;

    //@ assert n >= m;
    diff = n - m;
    
    //@ assert (diff == 0) ==> (n == m);
    result = (diff == 0);
    
    return result;
}
