#include <stdbool.h>

/*@ predicate two_equal_one_different(integer a, integer b, integer c) =
      (a == b && a != c) || (a == c && a != b) || (b == c && a != b);
*/

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> two_equal_one_different(a, b, c);
*/
bool func(int a, int b, int c)
{
    int count = 0;
    //@ assert count == 0;

    if (a == b)
    {
        count += 1;
    }
    //@ assert count == (a == b ? 1 : 0);

    if (a == c)
    {
        count += 1;
    }
    //@ assert count == (a == b ? 1 : 0) + (a == c ? 1 : 0);

    if (b == c)
    {
        count += 1;
    }
    //@ assert count == (a == b ? 1 : 0) + (a == c ? 1 : 0) + (b == c ? 1 : 0);

    //@ assert count == 1 <==> two_equal_one_different(a, b, c);

    if (count == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
