#include <stdbool.h>

/*@
    predicate is_mod3_zero(integer x) = x % 3 == 0;
    predicate is_sum_mod3_zero(integer a, integer b) = (a + b) % 3 == 0;
    predicate condition_holds(integer a, integer b) = 
        is_mod3_zero(a) || is_mod3_zero(b) || is_sum_mod3_zero(a, b);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == true <==> condition_holds(a, b);
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    
    if ((a % 3 == 0) || (b % 3 == 0) || ((a + b) % 3 == 0)) {
        //@ assert condition_holds(a, b);
        result = true;
    } else {
        //@ assert !condition_holds(a, b);
        result = false;
    }
    
    return result;
}
