/*@
    predicate is_in_range(integer n) = 1 <= n && n <= 100;
    predicate r_in_range(integer r) = 0 <= r && r <= 4111;

    logic integer max_val(integer n) =
        n >= 10 ? 0 : 100 * (10 - n);

    lemma max_val_bounds:
        \forall integer n; is_in_range(n) ==> 0 <= max_val(n) && max_val(n) <= 1000;
*/

/*@
    requires is_in_range(n);
    requires r_in_range(r);
    ensures \result == r + (n >= 10 ? 0 : 100 * (10 - n));
    assigns \nothing;
*/
int func(int n, int r)
{
    int max_val;
    int ans;

    //@ assert is_in_range(n);
    //@ assert r_in_range(r);

    max_val = (n >= 10) ? 0 : 100 * (10 - n);

    //@ assert max_val == (n >= 10 ? 0 : 100 * (10 - n));
    //@ assert 0 <= max_val && max_val <= 1000;

    ans = r + max_val;

    //@ assert ans == r + (n >= 10 ? 0 : 100 * (10 - n));

    return ans;
}
