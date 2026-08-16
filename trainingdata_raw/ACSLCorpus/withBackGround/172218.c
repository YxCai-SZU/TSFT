#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    
    logic integer condition(integer a, integer b) = 
        (a > b || a % 3 == 0 || b % 10 == 5) ? 1 : 0;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures \result == condition(a, b);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    bool result;
    
    //@ assert a_in_range(a) && b_in_range(b);
    
    if (a > b || a % 3 == 0 || b % 10 == 5) {
        //@ assert condition(a, b) == 1;
        result = true;
    } else {
        //@ assert condition(a, b) == 0;
        result = false;
    }
    
    return result;
}
