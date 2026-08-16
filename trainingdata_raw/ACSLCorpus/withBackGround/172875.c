/*@
    predicate valid_range(integer a, integer b) =
        2 <= a <= 100 && 2 <= b <= 100;

    logic integer compute_result(integer a, integer b) =
        (a - 1) * (b - 1);

    lemma no_underflow:
        \forall integer a, b;
            valid_range(a, b) ==> 1 <= a && 1 <= b;

    lemma no_overflow:
        \forall integer a, b;
            valid_range(a, b) ==> (a - 1) * (b - 1) <= 99 * 99;
*/

/*@
    requires valid_range(a, b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    int ans;

    //@ assert 1 <= a;
    //@ assert 1 <= b;
    //@ assert a - 1 <= 99;
    //@ assert b - 1 <= 99;
    //@ assert (a - 1) * (b - 1) <= 99 * 99;

    ans = (a - 1) * (b - 1);
    return ans;
}
