#include <stdbool.h>

/*@
    predicate is_in_range(integer v) =
        v < 0x8000000000000000 && v > -0x8000000000000000;
*/

/*@
    requires is_in_range(a) && is_in_range(b) && is_in_range(c);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(long long a, long long b, long long c)
{
    bool result;

    //@ assert is_in_range(a);
    //@ assert is_in_range(b);
    //@ assert is_in_range(c);
    
    if (a < b) {
        if (b < c) {
            //@ assert a < b && b < c;
            result = true;
        } else {
            //@ assert !(b < c);
            result = false;
        }
    } else {
        //@ assert !(a < b);
        result = false;
    }
    
    return result;
}
