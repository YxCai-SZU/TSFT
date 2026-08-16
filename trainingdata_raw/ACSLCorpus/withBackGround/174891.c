#include <stdbool.h>

/*@
    predicate is_in_range(integer n) = 1 <= n && n <= 100;
    predicate result_condition(integer n, bool result) = result == (n >= 13 || n <= 5);
*/

/*@
    requires is_in_range(n);
    ensures result_condition(n, \result);
    assigns \nothing;
*/
bool func(unsigned long n)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= n && n <= 100;
    
    if (n >= 13) {
        // Implement the logic for n >= 13 here
    } else {
        // Implement the logic for n < 13 here
    }
    
    result = (n >= 13 || n <= 5);
    return result;
}
