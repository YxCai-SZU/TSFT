#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = -40 <= x <= 40;
    predicate result_implies_ge30(bool r, integer x) = r ==> x >= 30;
    predicate not_result_implies_lt30(bool r, integer x) = !r ==> x < 30;
*/

/*@
    requires is_valid_range(X);
    ensures result_implies_ge30(\result, X);
    ensures not_result_implies_lt30(\result, X);
*/
bool func(int X)
{
    bool result;
    
    //@ assert -40 <= X <= 40;
    
    if (X >= 30)
    {
        result = true;
        //@ assert result ==> X >= 30;
    }
    else
    {
        //@ assert X < 30;
        result = false;
        //@ assert !result ==> X < 30;
    }
    
    return result;
}
