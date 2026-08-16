#include <stdbool.h>

/*@ predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate a_non_neg(integer a) = a >= 0;
    predicate b_non_neg(integer b) = b >= 0;
    predicate result_condition(integer a, integer b, bool result) = 
        result == (a >= b + 1);
 */

/*@ requires a_in_range(a);
    requires b_in_range(b);
    requires a_non_neg(a);
    requires b_non_neg(b);
    ensures result_condition(a, b, \result);
 */
bool func(long a, long b)
{
    // Variable declarations at top of scope
    bool result;
    
    // Proof assertions
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert a_non_neg(a);
    //@ assert b_non_neg(b);
    
    result = (a >= (b + 1));
    return result;
}
