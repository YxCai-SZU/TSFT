#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer sum_bounds(integer x, integer y) = x + y;
    
    lemma sum_bound_lemma:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> sum_bounds(x, y) <= 20000;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    requires valid_range(d);
    ensures \result == (c <= b + d && c + d <= b + a);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    // Variable declarations at top of scope
    bool res;
    
    // Precondition assertions
    //@ assert 1 <= a && a <= 10000;
    //@ assert 1 <= b && b <= 10000;
    //@ assert 1 <= c && c <= 10000;
    //@ assert 1 <= d && d <= 10000;
    
    // Proof of bounds for intermediate sums
    //@ assert b + d <= 20000;
    //@ assert c + d <= 20000;
    //@ assert b + a <= 20000;
    
    res = (c <= b + d) && (c + d <= b + a);
    
    // Postcondition verification
    //@ assert res == (c <= b + d && c + d <= b + a);
    
    return res;
}
