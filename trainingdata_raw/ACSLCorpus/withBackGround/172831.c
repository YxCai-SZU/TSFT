/*@
    predicate valid_input(integer a, integer b, integer c) =
        2 <= a && a <= 1000000000 &&
        2 <= b && b <= 1000000000 &&
        2 <= c && c <= 1000000000;

    logic integer safe_sub(integer x, integer y) = x - y;

    logic integer compute_result(integer a, integer b, integer c) =
        (c - (b - 1) * (a - 1) > 0) ?
        (c - (b - 1) * (a - 1)) : 0;

    lemma bound_lemma:
        \forall integer a, b;
        valid_input(a, b, 2) ==>
        1 <= a - 1 && a - 1 <= 1000000000 - 1 &&
        1 <= b - 1 && b - 1 <= 1000000000 - 1;

    lemma product_bound_lemma:
        \forall integer a, b;
        (1 <= a - 1 && a - 1 <= 1000000000 - 1 &&
         1 <= b - 1 && b - 1 <= 1000000000 - 1) ==>
        (b - 1) * (a - 1) <= 1000000000 * 1000000000;
*/

/*@
    requires valid_input(a, b, c);
    ensures \result <= c;
    ensures \result >= 0;
    ensures \result == compute_result(a, b, c);
*/
long func(long a, long b, long c)
{
    long result;

    //@ assert 1 <= b - 1 && b - 1 <= 1000000000 - 1;
    //@ assert 1 <= a - 1 && a - 1 <= 1000000000 - 1;
    //@ assert (b - 1) * (a - 1) <= 1000000000 * 1000000000;

    if (c - (b - 1) * (a - 1) > 0)
    {
        result = c - (b - 1) * (a - 1);
    }
    else
    {
        result = 0;
    }

    //@ assert result <= c;
    //@ assert result >= 0;
    return result;
}
