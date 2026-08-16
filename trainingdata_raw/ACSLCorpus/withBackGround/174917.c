/*@
    predicate valid_range(integer v) = 1 <= v <= 500;

    predicate condition(integer a, integer b, integer c, integer d) =
        (a <= c && b >= d) || (a >= c && b <= d) || (c >= a && d <= b) || (c <= a && d >= b);
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == 1 <==> condition(a, b, c, d);
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int result = 0;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);

    if (a <= c && b >= d) {
        result = 1;
    } else if (a >= c && b <= d) {
        result = 1;
    } else if (c >= a && d <= b) {
        result = 1;
    } else if (c <= a && d >= b) {
        result = 1;
    } else {
        result = 0;
    }

    //@ assert result == 1 <==> condition(a, b, c, d);
    return result;
}
