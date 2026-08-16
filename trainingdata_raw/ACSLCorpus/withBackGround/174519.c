#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    predicate condition_a(integer a, integer b, integer c) =
        a == b + 1 && b + 1 == c + 1;

    predicate condition_b(integer a, integer b, integer c) =
        a + 1 == b && b == c + 1;

    predicate condition_c(integer a, integer b, integer c) =
        a + 1 == b + 1 && b + 1 == c;

    lemma arithmetic_bounds:
        \forall integer a, b, c;
        valid_range(a) && valid_range(b) && valid_range(c) ==>
        a + 1 <= 10 && b + 1 <= 10 && c + 1 <= 10;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    ensures \result == true <==> (condition_a(a, b, c) || condition_b(a, b, c) || condition_c(a, b, c));
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    
    //@ assert b + 1 <= 10;
    //@ assert a + 1 <= 10;
    //@ assert c + 1 <= 10;
    
    if ((a == b + 1 && b + 1 == c + 1) ||
        (a + 1 == b && b == c + 1) ||
        (a + 1 == b + 1 && b + 1 == c)) {
        return true;
    } else {
        return false;
    }
}
