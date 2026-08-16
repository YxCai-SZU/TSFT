#include <stdbool.h>

/*@
    predicate is_sum(integer a, integer b, integer c) =
        a + b == c || a + c == b || b + c == a;
*/

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result == (a + b == c || a + c == b || b + c == a);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long c)
{
    unsigned long ab;
    unsigned long bc;
    unsigned long ca;
    bool result;

    //@ assert a + b <= 200;
    //@ assert a + c <= 200;
    //@ assert b + c <= 200;

    ab = a + b;
    bc = b + c;
    ca = c + a;

    result = (ab == c) || (bc == a) || (ca == b);
    return result;
}
