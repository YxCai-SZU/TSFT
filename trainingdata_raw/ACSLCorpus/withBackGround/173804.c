#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10;
    
    logic integer sum(integer x, integer y) = x + y;
    
    lemma sum_bound:
        \forall integer x, y; valid_range(x) && valid_range(y) ==> sum(x, y) <= 20;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == true <==> (a == b + c || b == a + c || c == a + b);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long c)
{
    bool is_possible = false;
    
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert b + c <= 20;
    //@ assert a + c <= 20;
    //@ assert a + b <= 20;
    
    if (a == b + c || b == a + c || c == a + b) {
        is_possible = true;
    }
    
    //@ assert is_possible == true <==> (a == b + c || b == a + c || c == a + b);
    
    return is_possible;
}
