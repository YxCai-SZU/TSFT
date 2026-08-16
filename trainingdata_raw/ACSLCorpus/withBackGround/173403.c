#include <stdbool.h>

/*@
    predicate is_valid_input(integer x) = 1 <= x && x <= 9;
    
    predicate matches_special(integer x) = x == 3 || x == 5 || x == 7;
*/

/*@
    requires is_valid_input(x);
    ensures \result == true <==> matches_special(x);
    assigns \nothing;
*/
bool func(unsigned int x)
{
    bool result;
    
    //@ assert is_valid_input(x);
    
    if (x == 3 || x == 5 || x == 7)
    {
        result = true;
    }
    else
    {
        //@ assert 1 <= x && x <= 9;
        result = false;
    }
    
    return result;
}
