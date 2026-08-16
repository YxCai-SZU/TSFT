#include <stdbool.h>

/*@
    predicate is_in_range(integer a) =
        0 <= a <= 100;

    predicate is_valid_b(integer b) =
        2 <= b <= 1000 && b % 2 == 0;

    logic integer compute_result(integer a, integer b) =
        a < 13 ? 0 :
        a < 15 ? (b / 2) / 2 :
        a < 18 ? (b * 3 / 2) / 2 :
        b;

    lemma result_cases:
        \forall integer a, b;
            is_in_range(a) && is_valid_b(b) ==>
            compute_result(a, b) == (
                a < 13 ? 0 :
                a < 15 ? (b / 2) / 2 :
                a < 18 ? (b * 3 / 2) / 2 :
                b
            );
*/

/*@
    requires is_in_range(a);
    requires is_valid_b(b);
    ensures \result == compute_result(a, b);
    ensures (a < 13 ==> \result == 0);
    ensures (a >= 13 && a < 15 ==> \result == (b / 2) / 2);
    ensures (a >= 15 && a < 18 ==> \result == (b * 3 / 2) / 2);
    ensures (a >= 18 && a <= 100 ==> \result == b);
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int result;

    if (a < 13)
    {
        result = 0;
        //@ assert result == 0;
    }
    else if (a < 15)
    {
        //@ assert a >= 13 && a < 15;
        result = (b / 2) / 2;
        //@ assert result == (b / 2) / 2;
    }
    else if (a < 18)
    {
        //@ assert a >= 15 && a < 18;
        result = (b * 3 / 2) / 2;
        //@ assert result == (b * 3 / 2) / 2;
    }
    else
    {
        //@ assert a >= 18 && a <= 100;
        result = b;
        //@ assert result == b;
    }

    return result;
}
