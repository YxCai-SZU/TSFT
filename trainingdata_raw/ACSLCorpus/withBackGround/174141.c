#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b, integer c) =
        a <= 100 && b <= 100 && c <= 100 &&
        a > 0 && b > 0 && c > 0;
*/

/*@
    requires bounds(a, b, c);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert a <= 100;
    //@ assert b <= 100;
    //@ assert c <= 100;
    //@ assert a > 0;
    //@ assert b > 0;
    //@ assert c > 0;

    result = (a < b) && (b < c);
    return result;
}
