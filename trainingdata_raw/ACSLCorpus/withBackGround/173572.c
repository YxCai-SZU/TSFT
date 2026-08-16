#include <stdbool.h>

/*@
    predicate is_even(integer n) = n % 2 == 0;
    predicate is_odd(integer n) = n % 2 == 1;
    
    logic integer lower_bound(integer x) = x * 2;
    logic integer upper_bound_even(integer x) = x * 4;
    logic integer upper_bound_odd(integer x) = x * 4 - 1;
    
    lemma range_lemma_even: \forall integer x; 1 <= x <= 100 ==> lower_bound(x) <= upper_bound_even(x);
    lemma range_lemma_odd: \forall integer x; 1 <= x <= 100 ==> lower_bound(x) <= upper_bound_odd(x);
*/

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == true <==> 
        ((y % 2 == 0 && x * 2 <= y && y <= x * 4) || 
         (y % 2 == 1 && x * 2 <= y && y <= x * 4 - 1));
*/
bool func(unsigned long x, unsigned long y)
{
    bool result;
    
    //@ assert 1 <= x <= 100;
    //@ assert 1 <= y <= 100;
    
    if (y % 2 == 0)
    {
        //@ assert is_even(y);
        //@ assert lower_bound(x) <= upper_bound_even(x);
        
        if (x * 2 <= y && y <= x * 4)
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }
    else
    {
        //@ assert is_odd(y);
        //@ assert lower_bound(x) <= upper_bound_odd(x);
        
        if (x * 2 <= y && y <= x * 4 - 1)
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }
    
    //@ assert result == true <==> ((y % 2 == 0 && x * 2 <= y && y <= x * 4) || (y % 2 == 1 && x * 2 <= y && y <= x * 4 - 1));
    
    return result;
}
