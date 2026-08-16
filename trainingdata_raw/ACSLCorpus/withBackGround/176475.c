#include <stdbool.h>

/*@
    predicate is_sum(integer a, integer b, integer c) =
        a + b == c || a + c == b || b + c == a;
 */

/*@
    requires 1 <= a && a <= 5000;
    requires 1 <= b && b <= 5000;
    requires 1 <= c && c <= 5000;
    ensures \result == (a + b == c || a + c == b || b + c == a);
    assigns \nothing;
 */
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int ab;
    unsigned int bc;
    unsigned int ca;
    bool found;

    ab = a + b;
    bc = b + c;
    ca = c + a;
    found = false;

    if (ab == c)
    {
        found = true;
    }
    if (bc == a)
    {
        found = true;
    }
    if (ca == b)
    {
        found = true;
    }

    //@ assert ab == a + b;
    //@ assert bc == b + c;
    //@ assert ca == c + a;
    //@ assert found == (a + b == c || a + c == b || b + c == a);

    return found;
}
