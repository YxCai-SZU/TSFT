#include <limits.h>

/*@
    predicate in_range(integer x) = -100 <= x <= 100;

    logic integer func_result(integer a, integer b, integer c) =
        (a == b && b == c) ? 3 :
        (a != b && b != c && c != a) ? 0 : 2;

    lemma result_cases:
        \forall integer a, b, c;
            in_range(a) && in_range(b) && in_range(c) ==>
            (a == b && b == c) ==> func_result(a, b, c) == 3;

    lemma result_cases2:
        \forall integer a, b, c;
            in_range(a) && in_range(b) && in_range(c) ==>
            (a != b && b != c && c != a) ==> func_result(a, b, c) == 0;

    lemma result_cases3:
        \forall integer a, b, c;
            in_range(a) && in_range(b) && in_range(c) ==>
            ((a == b || b == c || c == a) && (a != b || b != c || c != a)) ==>
            func_result(a, b, c) == 2;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures (a == b && b == c) ==> \result == 3;
    ensures (a != b && b != c && c != a) ==> \result == 0;
    ensures ((a == b || b == c || c == a) && (a != b || b != c || c != a)) ==> \result == 2;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;

    //@ assert in_range(a) && in_range(b) && in_range(c);

    if (a == b)
    {
        if (b == c)
        {
            ans = 3;
            //@ assert a == b && b == c;
        }
        else
        {
            ans = 2;
            //@ assert (a == b || b == c || c == a) && (a != b || b != c || c != a);
        }
    }
    else if (b == c)
    {
        ans = 2;
        //@ assert (a == b || b == c || c == a) && (a != b || b != c || c != a);
    }
    else if (c == a)
    {
        ans = 2;
        //@ assert (a == b || b == c || c == a) && (a != b || b != c || c != a);
    }
    else
    {
        ans = 0;
        //@ assert a != b && b != c && c != a;
    }

    //@ assert ans == func_result(a, b, c);
    return ans;
}
