#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 9;

    logic integer count_matches(integer a, integer b, integer c) =
        (a == b ? 1 : 0) +
        (a == c ? 1 : 0) +
        (b == c ? 1 : 0);

    lemma count_bounds:
        \forall integer a, b, c;
        is_valid_range(a) && is_valid_range(b) && is_valid_range(c) ==>
        0 <= count_matches(a, b, c) <= 3;

    lemma result_correct:
        \forall integer a, b, c;
        is_valid_range(a) && is_valid_range(b) && is_valid_range(c) ==>
        (count_matches(a, b, c) == 1) ==
        ((a == b && a != c) || (a == c && a != b) || (b == c && b != a));
*/

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == ((a == b && a != c) || (a == c && a != b) || (b == c && b != a));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int cnt = 0;

    //@ assert is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
    //@ assert 0 <= cnt <= 3;

    if (a == b)
    {
        cnt += 1;
        //@ assert cnt == 1;
    }
    //@ assert 0 <= cnt <= 3;

    if (a == c)
    {
        cnt += 1;
        //@ assert cnt <= 2;
    }
    //@ assert 0 <= cnt <= 3;

    if (b == c)
    {
        cnt += 1;
        //@ assert cnt <= 3;
    }
    //@ assert 0 <= cnt <= 3;

    //@ assert cnt == count_matches(a, b, c);
    //@ assert (cnt == 1) == ((a == b && a != c) || (a == c && a != b) || (b == c && b != a));

    return cnt == 1;
}
