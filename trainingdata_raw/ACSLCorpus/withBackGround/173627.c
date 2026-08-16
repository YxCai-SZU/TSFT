#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    
    logic integer sum_val(integer a, integer b) = a + b;
    
    lemma sum_bounds: \forall integer a, b; 
        valid_range(a) && valid_range(b) ==> 1 <= sum_val(a, b) <= 200;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == (c >= a && c <= a + b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum;
    
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    
    sum = a + b;
    
    //@ assert sum == a + b;
    //@ assert 2 <= sum <= 200;
    
    if (c > sum)
    {
        //@ assert c > a + b;
        //@ assert !(c >= a && c <= a + b);
        return false;
    }
    else if (c >= a)
    {
        //@ assert c >= a;
        //@ assert c <= a + b;
        //@ assert c >= a && c <= a + b;
        return true;
    }
    else
    {
        //@ assert c < a;
        //@ assert c <= a + b;
        //@ assert !(c >= a && c <= a + b);
        return false;
    }
}
