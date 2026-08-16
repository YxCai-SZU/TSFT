#include <stdbool.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 10000;

    logic integer product(integer a, integer b) = a * b;

    lemma product_in_range:
        \forall integer a, b;
            in_range(a) && in_range(b) ==> product(a, b) <= 10000 * 10000;

    lemma comparison_valid:
        \forall integer a, b, c;
            in_range(a) && in_range(b) && in_range(c) ==> 
            (product(a, b) >= c ==> product(a, b) >= c);
*/

/*@
    requires in_range(d);
    requires in_range(t);
    requires in_range(s);
    ensures \result == (t * s >= d);
*/
bool func(long d, long t, long s)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert in_range(t);
    //@ assert in_range(s);
    //@ assert in_range(d);
    
    //@ assert product(t, s) <= 10000 * 10000;
    //@ assert product(t, s) >= d ==> product(t, s) >= d;
    
    result = (t * s >= d);
    return result;
}
