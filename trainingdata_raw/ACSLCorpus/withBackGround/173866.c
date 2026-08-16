#include <stdbool.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 10000;

    logic integer safe_mult(integer a, integer b) = a * b;

    lemma mult_bounds:
        \forall integer t, s;
            in_range(t) && in_range(s) ==>
            1 <= safe_mult(t, s) <= 100000000;
*/

/*@
    requires in_range(d) && in_range(t) && in_range(s);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at scope top
    bool ans;
    int product;

    //@ assert in_range(t);
    //@ assert in_range(s);
    
    product = t * s;
    
    //@ assert 1 <= product <= 100000000;
    //@ assert product == safe_mult(t, s);
    
    ans = d <= product;
    
    //@ assert ans == (d <= safe_mult(t, s));
    return ans;
}
