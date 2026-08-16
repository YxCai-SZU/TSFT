#include <stdbool.h>

/*@
    predicate is_pair(integer a, integer b, integer c) =
        (a == b && c != a && c != b) ||
        (a == c && b != a && b != c) ||
        (b == c && a != b && a != c);
 */

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> is_pair(a, b, c);
 */
bool func(unsigned long a, unsigned long b, unsigned long c)
{
    bool result;

    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;

    if (a == b && a != c)
    {
        //@ assert a == b && c != a && c != b;
        result = true;
        return result;
    }

    if (b == c && b != a)
    {
        //@ assert b == c && a != b && a != c;
        result = true;
        return result;
    }

    if (c == a && c != b)
    {
        //@ assert c == a && b != c && b != a;
        result = true;
        return result;
    }

    result = false;
    return result;
}
