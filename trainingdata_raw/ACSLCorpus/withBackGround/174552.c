#include <stdbool.h>

/*@
    predicate is_valid_triangle(integer a, integer b, integer c) =
        0 <= a <= 100 && 0 <= b <= 100 && 0 <= c <= 100;
*/

/*@
    logic integer triangle_condition(integer a, integer b, integer c) =
        (a + b == c ? 1 : 0) +
        (b + c == a ? 1 : 0) +
        (c + a == b ? 1 : 0);
*/

/*@
    lemma triangle_lemma:
        \forall integer a, b, c;
            is_valid_triangle(a, b, c) ==>
            (triangle_condition(a, b, c) != 0 <==>
                (a + b == c || a + c == b || b + c == a));
*/

/*@
    requires is_valid_triangle(a, b, c);
    ensures \result == true <==> (a + b == c || a + c == b || b + c == a);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int m = 0;

    //@ assert is_valid_triangle(a, b, c);
    
    if (a + b == c) {
        m += 1;
    }
    if (b + c == a) {
        m += 1;
    }
    if (c + a == b) {
        m += 1;
    }

    //@ assert m == triangle_condition(a, b, c);
    //@ assert m != 0 <==> (a + b == c || a + c == b || b + c == a);
    
    return m != 0;
}
