#include <limits.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_bounds:
        \forall integer a, b; valid_range(a) && valid_range(b) ==> 
        1 <= product(a, b) <= 100;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= product(a, b);
    ensures \result >= product(c, d);
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int result;
    
    //@ assert 1 <= a * b <= 100;
    //@ assert 1 <= c * d <= 100;
    
    if (a * b > c * d)
    {
        //@ assert a * b >= c * d;
        result = a * b;
    }
    else
    {
        //@ assert c * d >= a * b;
        result = c * d;
    }
    
    return result;
}
