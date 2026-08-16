#include <stdbool.h>

/*@
    requires (1 <= (x) && (x) <= 100000);
    ensures \result == (\old(x) / 100 * 100 <= \old(x) && (\old(x) / 100 + 1) * 100 > \old(x));
    assigns \nothing;
*/
bool func(int x)
{
    int n;
    bool result;

    //@ assert (1 <= (x) && (x) <= 100000);
    n = x / 100;
    
    //@ assert n == x / 100;
    
    result = (n * 100 <= x && (n + 1) * 100 > x);
    
    //@ assert result == (x / 100 * 100 <= x && (x / 100 + 1) * 100 > x);
    return result;
}
