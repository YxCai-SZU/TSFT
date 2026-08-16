#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = x > -9223372036854775808 && x < 9223372036854775807;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(long long a, long long b, long long c)
{
    bool result = false;
    //@ assert is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
    
    if (a < b)
    {
        if (b < c)
        {
            result = true;
        }
    }
    
    //@ assert result == (a < b && b < c);
    return result;
}
