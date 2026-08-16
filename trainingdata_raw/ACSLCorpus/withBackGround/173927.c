#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b, integer c) =
        0 <= a && a <= 20 &&
        0 <= b && b <= 20 &&
        0 <= c && c <= 20;

    logic integer max_product(integer a, integer b) = a * b;

    lemma product_bounds:
        \forall integer a, b;
        bounds(a, b, 0) ==> max_product(a, b) <= 400;
*/

/*@
    requires a <= 20 && b <= 20 && c <= 20;
    requires 0 <= a && 0 <= b && 0 <= c;
    ensures \result == (a * b <= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int product;

    //@ assert bounds(a, b, c);
    
    product = a * b;
    //@ assert product <= 400;
    
    result = (product <= c);
    //@ assert result == (a * b <= c);
    
    return result;
}
