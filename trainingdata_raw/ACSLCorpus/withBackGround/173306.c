#include <stdbool.h>

/*@
    predicate is_valid_input(integer a) = 3 <= a && a <= 9;
    predicate result_condition(integer a, bool result) = 
        result == (a == 5 || a == 3 || a == 7);
*/

/*@
    requires is_valid_input(a);
    ensures result_condition(a, \result);
    assigns \nothing;
*/
bool func(unsigned int a)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 3 <= a && a <= 9;
    
    result = (a == 5 || a == 3 || a == 7);
    return result;
}
