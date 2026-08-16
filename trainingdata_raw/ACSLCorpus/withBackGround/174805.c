#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b, integer c) =
        0 <= a <= 100 && 0 <= b <= 100 && 0 <= c <= 100;

    logic integer product(integer c, integer a) = c * a;

    lemma product_bounds:
        \forall integer c, a;
        bounds(a, 0, c) ==> 0 <= product(c, a) <= 10000;
*/

/*@
    requires bounds(a, b, c);
    ensures \result == (c * a >= b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    bool result;
    unsigned int product_val;

    //@ assert bounds(a, b, c);
    
    product_val = c * a;
    
    //@ assert 0 <= product_val <= 10000;
    
    result = (product_val >= b);
    
    //@ assert result == (c * a >= b);
    
    return result;
}
