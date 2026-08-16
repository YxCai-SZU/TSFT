#include <stdbool.h>

/*@
    predicate strictly_increasing(integer a, integer b, integer c) =
        a < b && b < c;
    predicate strictly_decreasing(integer a, integer b, integer c) =
        a > b && b > c;
    predicate monotonic_sequence(integer a, integer b, integer c) =
        strictly_increasing(a, b, c) || strictly_decreasing(a, b, c);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> ((a < b && b < c) || (a > b && b > c));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert a <= 100 && b <= 100 && c <= 100;
    //@ assert a >= 1 && b >= 1 && c >= 1;

    if ((a < b && b < c) || (a > b && b > c)) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
