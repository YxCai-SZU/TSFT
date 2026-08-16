#include <stdbool.h>

/*@
    predicate in_range(integer v) = 1 <= v && v <= 10000;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_bound:
        \forall integer x, y;
            in_range(x) && in_range(y) ==> product(x, y) <= 100000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == (a * b <= c * d);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert a <= 10000;
    //@ assert b <= 10000;
    //@ assert c <= 10000;
    //@ assert d <= 10000;
    
    //@ assert a * b <= 100000000;
    //@ assert c * d <= 100000000;
    
    if (a * b <= c * d) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
