#include <stdbool.h>

/*@
    predicate all_equal(integer a, integer b, integer c) =
        a == b && b == c;

    predicate two_equal(integer a, integer b, integer c) =
        (a == b || b == c || a == c) && !(a == b && b == c);

    predicate all_different(integer a, integer b, integer c) =
        a != b && b != c && a != c;

    lemma case_analysis:
        \forall integer a, b, c;
            all_equal(a, b, c) || two_equal(a, b, c) || all_different(a, b, c);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 1 && \result <= 3;
    ensures all_equal(a, b, c) ==> \result == 1;
    ensures two_equal(a, b, c) ==> \result == 2;
    ensures all_different(a, b, c) ==> \result == 3;
*/
int func(int a, int b, int c)
{
    int ans = -1;

    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;

    if (a == b && b == c)
    {
        ans = 1;
        //@ assert all_equal(a, b, c);
    }
    else if (a != b && b != c && a != c)
    {
        ans = 3;
        //@ assert all_different(a, b, c);
    }
    else
    {
        ans = 2;
        //@ assert two_equal(a, b, c);
    }

    //@ assert ans >= 1 && ans <= 3;
    return ans;
}
