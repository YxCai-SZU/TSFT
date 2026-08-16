#include <stdbool.h>

/*@
    predicate is_in_range(integer x) = 1 <= x <= 100;
*/

/*@
    requires is_in_range(a) && is_in_range(b) && is_in_range(c);
    ensures \result == ((a <= c && c <= b) || (a <= b && b <= c));
*/
bool func(int a, int b, int c)
{
    bool ok = false;
    
    //@ assert is_in_range(a) && is_in_range(b) && is_in_range(c);
    
    if (a <= c && c <= b) {
        ok = true;
    }
    
    if (a <= b && b <= c) {
        ok = true;
    }
    
    //@ assert ok == ((a <= c && c <= b) || (a <= b && b <= c));
    
    return ok;
}
