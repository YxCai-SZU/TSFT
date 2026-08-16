#include <stdbool.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 5000;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_bound:
        \forall integer x, y;
            in_range(x) && in_range(y) ==> product(x, y) <= 25000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == (product(a, b) > product(c, d));
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    bool result = false;
    
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert in_range(d);
    
    //@ assert product(a, b) <= 25000000;
    //@ assert product(c, d) <= 25000000;
    
    if (a * b > c * d) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
