#include <limits.h>

/*@
    predicate in_range(integer v) = -100 <= v <= 100;

    logic integer count_eq(integer a, integer b, integer c) =
        (a == b ? 1 : 0) + (b == c ? 1 : 0) + (a == c ? 1 : 0);

    lemma cnt_range:
        \forall integer a, b, c;
        in_range(a) && in_range(b) && in_range(c) ==>
        0 <= count_eq(a, b, c) <= 3;

    lemma cnt_3_implies_all_eq:
        \forall integer a, b, c;
        count_eq(a, b, c) == 3 ==> a == b && b == c;

    lemma cnt_2_implies_two_eq:
        \forall integer a, b, c;
        count_eq(a, b, c) == 2 ==>
        (a == b && b != c) || (a != b && b == c) || (a == c && b != c);

    lemma cnt_0_implies_all_diff:
        \forall integer a, b, c;
        count_eq(a, b, c) == 0 ==> a != b && b != c && a != c;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures (a == b && b == c) ==> \result == 1;
    ensures (a == b && b != c) ==> \result == 2;
    ensures (a != b && b == c) ==> \result == 2;
    ensures (a == c && b != c) ==> \result == 2;
    ensures (a != b && b != c && a != c) ==> \result == 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int x = a;
    int y = b;
    int z = c;
    int cnt = 0;

    //@ assert in_range(x) && in_range(y) && in_range(z);
    //@ assert count_eq(x, y, z) == count_eq(a, b, c);

    if (x == y)
    {
        cnt += 1;
    }
    if (y == z)
    {
        cnt += 1;
    }
    if (x == z)
    {
        cnt += 1;
    }

    //@ assert cnt == count_eq(a, b, c);
    //@ assert 0 <= cnt <= 3;

    if (cnt == 3)
    {
        //@ assert a == b && b == c;
        return 1;
    }
    else if (cnt == 2)
    {
        //@ assert (a == b && b != c) || (a != b && b == c) || (a == c && b != c);
        return 2;
    }
    else if (cnt == 1)
    {
        //@ assert (a == b && b != c) || (a != b && b == c) || (a == c && b != c);
        return 2;
    }
    else
    {
        //@ assert a != b && b != c && a != c;
        return 3;
    }
}
