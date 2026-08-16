#include <stdbool.h>

/*@
    predicate in_range(integer x) = 1 <= x <= 9;
    predicate product_le_80(integer x, integer y) = x * y <= 80;
    predicate product_le_81(integer x, integer y) = x * y <= 81;
*/

/*@
    lemma product_bound:
        \forall integer a, b;
            in_range(a) && in_range(b) ==> product_le_81(a, b);
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == (a * b <= 80 && b * c <= 80 && c * a <= 80);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    
    //@ assert product_le_81(a, b);
    //@ assert product_le_81(b, c);
    //@ assert product_le_81(c, a);
    
    result = (a * b <= 80) && (b * c <= 80) && (c * a <= 80);
    return result;
}
