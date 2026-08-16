/*@
    predicate valid_range(integer v) = 1 <= v <= 100;

    logic integer compute_ans(integer a, integer b) = a - (b * 2);

    lemma ans_property:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==>
        compute_ans(a,b) >= 0 ==> compute_ans(a,b) <= a;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    ensures \result >= 0;
    ensures \result <= a;
    ensures \result == compute_ans(a,b) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int ans;
    int tmp;

    tmp = b * 2;
    ans = a - tmp;

    //@ assert ans == compute_ans(a,b);

    if (ans < 0)
    {
        ans = 0;
    }

    //@ assert ans >= 0;
    //@ assert ans <= a;
    //@ assert ans == compute_ans(a,b) || ans == 0;

    return ans;
}
