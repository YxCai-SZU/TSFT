#include <stdbool.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 13;

    logic integer sum(integer a, integer b, integer c) = a + b + c;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == (sum(a, b, c) >= 22);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int n;

    n = a + b + c;

    //@ assert n == sum(a, b, c);

    return n >= 22;
}
