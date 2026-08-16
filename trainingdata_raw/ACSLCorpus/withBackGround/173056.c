/*@
    predicate valid_inputs(integer n, integer r) =
        1 <= n && n <= 100 &&
        0 <= r && r <= 4111;

    logic integer compute_result(integer n, integer r) =
        n >= 10 ? r : r + 100 * (10 - n);

    lemma result_verification:
        \forall integer n, r;
        valid_inputs(n, r) ==> compute_result(n, r) == (n >= 10 ? r : r + 100 * (10 - n));
*/

/*@
    requires valid_inputs(n, r);
    ensures \result == compute_result(n, r);
    assigns \nothing;
*/
int func(int n, int r)
{
    unsigned int n_unsigned;
    unsigned int r_unsigned;
    int res;

    if (n < 10)
    {
        n_unsigned = 10 - (unsigned int)n;
        r_unsigned = (unsigned int)r;
        //@ assert n_unsigned == 10 - (unsigned int)n;
        //@ assert r_unsigned == (unsigned int)r;
    }
    else
    {
        n_unsigned = 0;
        r_unsigned = 0;
        //@ assert n_unsigned == 0;
        //@ assert r_unsigned == 0;
    }

    if (n >= 10)
    {
        res = r;
    }
    else
    {
        res = r + 100 * (10 - n);
    }

    //@ assert res == compute_result(n, r);
    return res;
}
