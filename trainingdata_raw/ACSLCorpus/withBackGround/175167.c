#include <stdbool.h>

/*@
    predicate all_equal(integer a, integer b, integer c) =
        a == b && b == c;

    logic integer count_matches(integer a, integer b, integer c) =
        (a == b ? 1 : 0) +
        (b == c ? 1 : 0) +
        (c == a ? 1 : 0);

    lemma count_range:
        \forall integer a, b, c;
            1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 ==>
            count_matches(a, b, c) >= 0 && count_matches(a, b, c) <= 3;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> (a == b && b == c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int count = 0;

    if (a == b && b == c)
    {
        //@ assert all_equal(a, b, c);
        return true;
    }
    else
    {
        if (a == b)
        {
            count += 1;
        }
        if (b == c)
        {
            count += 1;
        }
        if (c == a)
        {
            count += 1;
        }

        //@ assert count == count_matches(a, b, c);
        //@ assert count >= 0 && count <= 3;

        if (count == 0)
        {
            return false;
        }
        else
        {
            return false;
        }
    }
}
