/*@
    predicate valid_params(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_x(integer a, integer b) = a - b;
    logic integer compute_result(integer c, integer x) =
        (c - x < 0) ? 0 : (c - x);

    lemma result_bounds:
        \forall integer a, b, c, x, result;
        valid_params(a, b, c) &&
        x == compute_x(a, b) &&
        result == compute_result(c, x) ==>
        result >= 0 &&
        result <= c &&
        (c - (a - b)) <= result;
*/

/*@
    requires valid_params(a, b, c);
    ensures \result >= 0;
    ensures \result <= c;
    ensures (c - (a - b)) <= \result;
*/
int func(int a, int b, int c)
{
    int x;
    int result;

    x = a - b;
    //@ assert x == compute_x(a, b);

    if (c - x < 0)
    {
        result = 0;
    }
    else
    {
        result = c - x;
    }
    //@ assert result == compute_result(c, x);

    //@ assert result >= 0;
    //@ assert result <= c;
    //@ assert (c - (a - b)) <= result;

    return result;
}
