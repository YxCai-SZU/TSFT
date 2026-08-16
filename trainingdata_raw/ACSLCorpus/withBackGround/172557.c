#include <stdbool.h>

/*@
    predicate is_triangle(integer a, integer b, integer c) =
        a > 0 && b > 0 && c > 0 &&
        a + b > c && a + c > b && b + c > a;

    predicate is_equilateral(integer a, integer b, integer c) =
        a == b && b == c;

    lemma triangle_inequality:
        \forall integer a, b, c;
            is_triangle(a, b, c) ==> a + b > c && a + c > b && b + c > a;
*/

/*@
    requires is_triangle(a, b, c);
    ensures \result == true <==> is_equilateral(a, b, c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert is_triangle(a, b, c);
    
    if (a == b && b == c) {
        result = true;
    } else {
        //@ assert a + b > c && a + c > b && b + c > a;
        result = false;
    }
    
    return result;
}
