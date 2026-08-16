/*@
    predicate is_nonnegative(integer x) = x >= 0;

    logic integer compute_result(integer a, integer b) =
        a - 2 * b > 0 ? a - 2 * b : 0;

    lemma result_nonnegative:
        \forall integer a, b;
        1 <= a <= 100 && 1 <= b <= 100 ==>
        compute_result(a, b) >= 0;

    lemma result_cases:
        \forall integer a, b;
        1 <= a <= 100 && 1 <= b <= 100 ==>
        compute_result(a, b) == a - 2 * b ||
        compute_result(a, b) == 0;
*/


int func(int a, int b)
{
    int result;

    //@ assert 1 <= a <= 100 && 1 <= b <= 100;

    if (a - 2 * b > 0)
    {
        //@ assert a - 2 * b > 0;
        result = a - 2 * b;
    }
    else
    {
        //@ assert a - 2 * b <= 0;
        result = 0;
    }

    //@ assert result >= 0;
    //@ assert result == a - 2 * b || result == 0;

    return result;
}
