#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate both_in_range(integer a, integer b) = 
        a_in_range(a) && b_in_range(b);
*/

/*@
    requires both_in_range(a, b);
    ensures \result == (b >= a);
    assigns \nothing;
*/
bool func(long a, long b)
{
    bool answer = false;
    
    //@ assert both_in_range(a, b);
    
    if (b >= a)
    {
        answer = true;
    }
    
    //@ assert answer == (b >= a);
    
    return answer;
}
