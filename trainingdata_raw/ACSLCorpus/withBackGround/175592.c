/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer compute_diff(integer a, integer b) = a - b * 2;

    lemma diff_nonnegative_or_zero:
        \forall integer a, b;
        valid_range(a, b) ==> (compute_diff(a, b) >= 0 || compute_diff(a, b) < 0);
*/

/*@
    requires valid_range(a, b);
    ensures \result >= 0;
    ensures \result == compute_diff(a, b) || \result == 0;
*/
int func(int a, int b)
{
    int result;
    //@ assert valid_range(a, b);
    result = a - b * 2;
    //@ assert result == compute_diff(a, b);
    if (result < 0)
    {
        //@ assert compute_diff(a, b) < 0;
        result = 0;
        //@ assert result == 0;
    }
    //@ assert result >= 0 && (result == compute_diff(a, b) || result == 0);
    return result;
}
