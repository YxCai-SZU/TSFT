/*@
    predicate valid_params(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_result(integer a, integer b, integer c) =
        (c - (a - b)) < 0 ? 0 : (c - (a - b));
*/

/*@
    requires valid_params(a, b, c);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == c - (a - b) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int raw;

    //@ assert valid_params(a, b, c);
    raw = c - (a - b);
    result = raw < 0 ? 0 : raw;

    //@ assert result >= 0;
    //@ assert result <= c;
    //@ assert result == c - (a - b) || result == 0;
    return result;
}
