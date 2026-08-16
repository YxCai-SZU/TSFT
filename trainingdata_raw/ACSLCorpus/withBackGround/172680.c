#include <stdbool.h>

/*@
    predicate is_in_range(integer x) = -40 <= x && x <= 40;
    predicate is_integer(integer x) = x == (int)x;
*/

/*@
    requires is_in_range(x) && is_integer(x);
    ensures \result == (x >= 30);
    assigns \nothing;
*/
bool func(int x)
{
    // Variable declarations at scope top
    int i;
    bool result;

    //@ assert is_in_range(x) && is_integer(x);
    
    if (x >= 30)
    {
        result = true;
    }
    else
    {
        i = 0;
        /*@
            loop invariant 0 <= i <= 10;
            loop invariant is_in_range(x) && is_integer(x);
            loop assigns i;
            loop variant 10 - i;
        */
        while (i < 10)
        {
            i = i + 1;
        }
        //@ assert x < 30;
        result = false;
    }
    
    return result;
}
