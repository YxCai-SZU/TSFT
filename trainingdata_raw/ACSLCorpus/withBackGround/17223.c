#include <stdbool.h>

/*@
    predicate valid_temp(integer x) = -40 <= x <= 40;
    predicate result_condition(integer x, bool r) = r == (x >= 30);
*/

/*@
    requires valid_temp(x);
    ensures \result == (x >= 30);
    assigns \nothing;
*/
bool func(int x)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert -40 <= x <= 40;
    
    //@ assert x >= 30 ==> x >= 30;
    
    result = (x >= 30);
    
    //@ assert result == (x >= 30);
    return result;
}

int main(void)
{
    return 0;
}
