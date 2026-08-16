#include <limits.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 100;

    logic integer func_result(integer a, integer b, integer c) =
        (a == b && b == c) ? 1 :
        (a != b && b != c && a != c) ? 3 : 2;

    lemma result_range:
        \forall integer a, b, c;
            in_range(a) && in_range(b) && in_range(c) ==>
            1 <= func_result(a, b, c) <= 3;

    lemma result_1_meaning:
        \forall integer a, b, c;
            in_range(a) && in_range(b) && in_range(c) ==>
            (func_result(a, b, c) == 1 ==> a == b && b == c);

    lemma result_2_meaning:
        \forall integer a, b, c;
            in_range(a) && in_range(b) && in_range(c) ==>
            (func_result(a, b, c) == 2 ==>
                (a == b && b != c) || (a == c && a != b) || (b == c && b != a));

    lemma result_3_meaning:
        \forall integer a, b, c;
            in_range(a) && in_range(b) && in_range(c) ==>
            (func_result(a, b, c) == 3 ==> a != b && b != c && a != c);
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> (a == b && b == c);
    ensures \result == 2 ==> ((a == b && b != c) || (a == c && a != b) || (b == c && b != a));
    ensures \result == 3 ==> (a != b && b != c && a != c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans = -1;

    //@ assert in_range(a) && in_range(b) && in_range(c);

    if (a == b && b == c)
    {
        ans = 1;
        //@ assert ans == 1;
        //@ assert a == b && b == c;
    }
    else if (a != b && b != c && a != c)
    {
        ans = 3;
        //@ assert ans == 3;
        //@ assert a != b && b != c && a != c;
    }
    else
    {
        ans = 2;
        //@ assert ans == 2;
        //@ assert (a == b && b != c) || (a == c && a != b) || (b == c && b != a);
    }

    //@ assert ans >= 1 && ans <= 3;
    return ans;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    assert(func(1, 1, 1) == 1);
    assert(func(1, 2, 3) == 3);
    assert(func(1, 1, 2) == 2);
    return 0;
}
#endif
