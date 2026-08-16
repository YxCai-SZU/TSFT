#include <stdbool.h>

/*@
    predicate is_valid_triangle(integer a, integer b, integer c) =
        1 <= a && a <= 10000 &&
        1 <= b && b <= 10000 &&
        1 <= c && c <= 10000;

    lemma triangle_inequality:
        \forall integer a, b, c;
            is_valid_triangle(a, b, c) ==>
            (a + b == c || a + c == b || b + c == a) ==>
            \true;
*/

/*@
    requires 1 <= a && a <= 10000;
    requires 1 <= b && b <= 10000;
    requires 1 <= c && c <= 10000;
    ensures \result == true <==> a + b == c || a + c == b || b + c == a;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert 1 <= a && a <= 10000;
    //@ assert 1 <= b && b <= 10000;
    //@ assert 1 <= c && c <= 10000;
    
    return (a + b == c) || (a + c == b) || (b + c == a);
}
