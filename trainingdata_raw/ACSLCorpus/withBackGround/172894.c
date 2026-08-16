#include <limits.h>

/*@
    predicate in_range(integer a) = -1000 <= a <= 1000;
    
    logic integer sum(integer a, integer b) = a + b;
    logic integer diff(integer a, integer b) = a - b;
    logic integer prod(integer a, integer b) = a * b;
    
    lemma product_bounds:
        \forall integer a, b;
        in_range(a) && in_range(b) ==> 
        -1000000 <= prod(a, b) <= 1000000;
*/

/*@
    requires in_range(a) && in_range(b);
    ensures \result == sum(a, b) || 
            \result == diff(a, b) || 
            \result == prod(a, b);
    ensures \result >= sum(a, b);
    ensures \result >= diff(a, b);
    ensures \result >= prod(a, b);
*/
int func(int a, int b)
{
    int max_val;
    
    //@ assert -1000000 <= a * b <= 1000000;
    
    if (a * b > a + b)
    {
        if (a * b > a - b)
        {
            max_val = a * b;
        }
        else
        {
            max_val = a - b;
        }
    }
    else
    {
        if (a + b > a - b)
        {
            max_val = a + b;
        }
        else
        {
            max_val = a - b;
        }
    }
    
    //@ assert max_val >= a + b;
    //@ assert max_val >= a - b;
    //@ assert max_val >= a * b;
    
    return max_val;
}
