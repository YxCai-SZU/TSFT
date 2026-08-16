#include <stdbool.h>

/*@ predicate is_less(integer a, integer b) = a < b; */

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    ensures \result == (a < b);
    assigns \nothing;
*/
bool func(int a, int b)
{
    bool result;
    
    if (a < b) {
        //@ assert is_less(a, b);
        result = true;
    } else {
        //@ assert !is_less(a, b);
        result = false;
    }
    
    return result;
}
