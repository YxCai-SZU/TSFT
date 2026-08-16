#include <stdbool.h>

/*@
    predicate condition_holds(integer k, integer x) =
        500 * k >= x;
*/

/*@
    requires 1 <= k <= 100;
    requires 1 <= x <= 100000;
    ensures \result == true <==> 500 * k >= x;
    assigns \nothing;
*/
bool func(int k, int x)
{
    bool result;
    
    //@ assert 1 <= k <= 100;
    //@ assert 1 <= x <= 100000;
    
    if (500 * k >= x) {
        //@ assert condition_holds(k, x);
        result = true;
    } else {
        //@ assert !condition_holds(k, x);
        result = false;
    }
    
    //@ assert result == true <==> 500 * k >= x;
    return result;
}
