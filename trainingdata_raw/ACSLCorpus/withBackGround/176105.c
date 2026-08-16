/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    predicate output_range(integer ans, integer c) =
        ans >= 0 && ans <= c;
*/

/*@
    requires valid_input(a, b, c);
    ensures output_range(\result, c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;
    ans = c - (a - b);
    if (ans > 0)
    {
        //@ assert ans <= c;
        return ans;
    }
    else
    {
        return 0;
    }
}

/*@
    lemma ans_bound_lemma:
        \forall integer a, b, c, ans;
        valid_input(a, b, c) &&
        ans == c - (a - b) &&
        ans > 0 ==>
        ans <= c;
*/

/*@
    requires valid_input(a, b, c);
    ensures output_range(\result, c);
    assigns \nothing;
*/
int func2(int a, int b, int c)
{
    int ans;
    ans = c - (a - b);
    if (ans > 0)
    {
        //@ assert ans <= c;
        return ans;
    }
    else
    {
        return 0;
    }
}
