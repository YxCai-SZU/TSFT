#include <stdbool.h>

/*@
    predicate is_multiple_of_200(integer x) = x % 200 == 0;
    predicate within_next_200(integer x) = (x / 200 + 1) * 200 - x < 200;
    predicate result_condition(integer x) = is_multiple_of_200(x) || within_next_200(x);
*/

/*@
    requires 1 <= x <= 100000;
    ensures \result == true <==> result_condition(x);
    assigns \nothing;
*/
bool func(unsigned int x)
{
    unsigned int div;
    unsigned int rem;
    unsigned int rem2;
    
    div = x / 200;
    rem = x % 200;
    
    if (rem == 0)
    {
        //@ assert is_multiple_of_200(x);
        return true;
    }
    
    rem2 = (div + 1) * 200 - x;
    
    if (rem2 < 200)
    {
        //@ assert within_next_200(x);
        return true;
    }
    
    //@ assert div + 1 <= 100000;
    //@ assert (div + 1) * 200 <= 200000;
    //@ assert (div + 1) * 200 >= x;
    
    return false;
}
