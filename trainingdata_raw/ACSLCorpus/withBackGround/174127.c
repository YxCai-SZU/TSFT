#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 5000;
    
    lemma product_bound:
        \forall integer x, y; 
        valid_range(x) && valid_range(y) ==> 
        0 <= x * y <= 5000 * 5000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == (a * c <= b * d);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert valid_range(c) && valid_range(d);
    //@ assert 0 <= b * d <= 5000 * 5000;
    
    //@ assert valid_range(a) && valid_range(c);
    //@ assert 0 <= a * c <= 5000 * 5000;
    
    result = (a * c <= b * d);
    return result;
}
