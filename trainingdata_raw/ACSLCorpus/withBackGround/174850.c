#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;
    
    logic integer safe_mult(integer a, integer b) = a * b;
    
    lemma mult_bounds:
        \forall integer t, s;
            valid_range(t) && valid_range(s) ==> 
            safe_mult(t, s) <= 10000 * 10000;
*/

/*@
    requires valid_range(d) && valid_range(t) && valid_range(s);
    ensures \result == true <==> d <= t * s;
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    int distance;
    
    //@ assert valid_range(t);
    //@ assert valid_range(s);
    //@ assert safe_mult(t, s) <= 10000 * 10000;
    
    distance = t * s;
    
    if (d <= distance)
    {
        //@ assert d <= t * s;
        return true;
    }
    else
    {
        //@ assert !(d <= t * s);
        return false;
    }
}
