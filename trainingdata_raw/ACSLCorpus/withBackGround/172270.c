#include <stdbool.h>

/*@
    predicate can_distribute_evenly(integer a, integer b, integer c) =
        a + b == c || a + c == b || b + c == a;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result <==> (a + b == c || a + c == b || b + c == a);
    assigns \nothing;
*/
bool can_distribute_evenly(unsigned int a, unsigned int b, unsigned int c)
{
    bool can_distribute;
    
    can_distribute = (a + b == c) || (a + c == b) || (b + c == a);
    
    //@ assert can_distribute <==> (a + b == c || a + c == b || b + c == a);
    
    return can_distribute;
}
