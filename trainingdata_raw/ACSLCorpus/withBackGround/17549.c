/*@
    predicate valid_range(integer x) = 1 <= x && x <= 100;

    lemma b_mult_bound: \forall integer b; valid_range(b) ==> b * 2 <= 200;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    ensures \result >= 0;
    ensures \result == a - b * 2 || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int ans;
    //@ assert b * 2 <= 200;
    ans = a - b * 2;
    if (ans < 0)
    {
        return 0;
    }
    else
    {
        return ans;
    }
}
