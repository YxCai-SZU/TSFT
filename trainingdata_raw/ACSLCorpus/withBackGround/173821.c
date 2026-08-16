#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer safe_sub(integer x, integer y) = x - y;

    lemma subtraction_bounds:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> 
            -99 <= safe_sub(b, a) <= 99;

    lemma equality_check:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            (safe_sub(b, a) == safe_sub(c, b)) || 
            (safe_sub(b, a) != safe_sub(c, b));
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == (b - a == c - b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    
    //@ assert -99 <= b - a <= 99;
    //@ assert -99 <= c - b <= 99;
    
    //@ assert -198 <= c - a <= 198;
    
    //@ assert b - a == c - b || b - a != c - b;
    
    result = (b - a == c - b);
    return result;
}
