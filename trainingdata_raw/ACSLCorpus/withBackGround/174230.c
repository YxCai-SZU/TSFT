#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b, integer c) =
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;

    logic integer square(integer x) = x * x;
    logic integer product(integer x, integer y) = x * y;

    lemma square_bound:
        \forall integer c; 1 <= c <= 100 ==> square(c) <= 10000;

    lemma product_bound:
        \forall integer a, b; 1 <= a <= 100 && 1 <= b <= 100 ==> product(a, b) <= 10000;
*/

/*@
    requires bounds(a, b, c);
    ensures \result == (c * c < a * b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert 1 <= c <= 100;
    //@ assert c * c <= 10000;
    
    //@ assert 1 <= a <= 100 && 1 <= b <= 100;
    //@ assert a * b <= 10000;
    
    return c * c < a * b;
}
