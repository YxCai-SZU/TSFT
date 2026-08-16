#include <stdbool.h>

/*@
    predicate in_range(integer v) = 0 <= v <= 100;

    logic integer safe_sum(integer x, integer b) = x + b;

    lemma sum_in_range:
        \forall integer x, b;
        in_range(x) && in_range(b) ==> 0 <= safe_sum(x, b) <= 200;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(x);
    ensures \result == (x <= a && a <= x + b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    // Variable declarations at scope top
    bool result;

    //@ assert in_range(x);
    //@ assert in_range(b);
    //@ assert safe_sum(x, b) == x + b;
    
    result = (x <= a && a <= x + b);
    
    //@ assert result == (x <= a && a <= x + b);
    return result;
}
