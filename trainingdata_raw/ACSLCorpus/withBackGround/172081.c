/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_minus(integer a, integer b) = a - b;

    logic integer compute_ans(integer c, integer minus) =
        c - minus < 0 ? 0 : c - minus;

    lemma ans_bounds:
        \forall integer a, b, c, minus, ans;
        valid_input(a, b, c) &&
        minus == compute_minus(a, b) &&
        ans == compute_ans(c, minus) ==>
        ans >= 0 && ans <= c;
*/

/*@
    requires valid_input(a, b, c);
    ensures \result >= 0 && \result <= c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int minus;
    int ans;

    minus = a - b;

    //@ assert minus == compute_minus(a, b);

    if (c - minus < 0)
    {
        ans = 0;
    }
    else
    {
        ans = c - minus;
    }

    //@ assert ans == compute_ans(c, minus);
    //@ assert ans >= 0 && ans <= c;

    return ans;
}
