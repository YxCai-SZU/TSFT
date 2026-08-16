#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer compute_answer(integer a, integer b) =
        a - b * 2;

    predicate answer_nonnegative(integer ans) =
        ans >= 0;

    lemma answer_bound: \forall integer a, b;
        valid_range(a, b) ==> compute_answer(a, b) <= a;
*/

/*@
    requires valid_range(a, b);
    ensures \result >= 0;
    ensures \result <= a;
    ensures \result == compute_answer(a, b) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int answer;
    int result;

    answer = a - b * 2;

    //@ assert answer == compute_answer(a, b);

    if (answer < 0)
    {
        //@ assert answer < 0;
        result = 0;
    }
    else
    {
        //@ assert answer >= 0;
        result = answer;
    }

    //@ assert result >= 0;
    //@ assert result == compute_answer(a, b) || result == 0;
    return result;
}
