#include <limits.h>

/*@
    predicate is_valid_input(integer a, integer b) =
        0 <= a <= 100 &&
        2 <= b <= 1000 &&
        b % 2 == 0;

    logic integer half_of(integer b) = b / 2;

    lemma half_of_property:
        \forall integer b; is_valid_input(0, b) ==> 0 <= half_of(b) <= b;

    lemma division_correctness:
        \forall integer b; is_valid_input(0, b) ==> half_of(b) * 2 == b;
*/

/*@
    requires is_valid_input(a, b);
    ensures \result >= 0 && \result <= b;
    ensures a < 6 ==> \result == 0;
    ensures 6 <= a && a < 13 ==> \result == b / 2;
    ensures a >= 13 ==> \result == b;
*/
int func(int a, int b)
{
    int result;

    //@ assert is_valid_input(a, b);

    if (a < 6)
    {
        result = 0;
        //@ assert result == 0;
    }
    else if (a < 13)
    {
        int half_b = 0;
        int count = 0;

        /*@
            loop invariant 0 <= half_b <= b / 2;
            loop invariant 0 <= count <= b;
            loop invariant count % 2 == 0;
            loop invariant half_b * 2 == count;
            loop invariant is_valid_input(a, b);
            loop assigns half_b, count;
            loop variant b - count;
        */
        while (count < b)
        {
            half_b += 1;
            count += 2;
            //@ assert half_b * 2 == count;
        }

        result = half_b;
        //@ assert result == b / 2;
    }
    else
    {
        result = b;
        //@ assert result == b;
    }

    //@ assert result >= 0 && result <= b;
    return result;
}
