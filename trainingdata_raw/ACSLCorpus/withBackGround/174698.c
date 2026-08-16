/*@
    predicate valid_params(integer a, integer b, integer c) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 20 &&
        1 <= c && c <= 2000;

    logic integer compute_sum(integer a, integer b) = a + b * 2;
*/

/*@
    requires valid_params(a, b, c);
    ensures \result <= c;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int sum;
    sum = a + b * 2;

    if (sum < c)
    {
        //@ assert sum >= 0;
        return sum;
    }
    else
    {
        //@ assert c >= 0;
        return c;
    }
}
