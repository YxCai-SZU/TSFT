#include <stdbool.h>

/*@ predicate is_valid_range(integer x) = 1 <= x <= 9; */

/*@
    requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
    ensures \result == ((a == b && a != c) || (a == c && a != b) || (b == c && b != a));
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
    
    result = (a == b && a != c) || (a == c && a != b) || (b == c && b != a);
    
    //@ assert result == ((a == b && a != c) || (a == c && a != b) || (b == c && b != a));
    
    return result;
}
