#include <stdbool.h>

/*@
    predicate is_valid_range(integer v) = 1 <= v <= 100;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
    ensures \result == ((a < b && c < b) || (b < a && b < c));
*/
bool func(int a, int b, int c)
{
    bool r;
    
    //@ assert is_valid_range(a);
    
    if (a < b && c < b) {
        r = true;
    } else {
        r = false;
    }
    
    //@ assert r == (a < b && c < b);
    
    if (b < a && b < c) {
        r = true;
    }
    
    //@ assert r == ((a < b && c < b) || (b < a && b < c));
    
    return r;
}
