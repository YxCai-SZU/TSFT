/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    predicate pi_val(integer pi) = pi == 314;
    predicate divisor_val(integer d) = d == 100;
    predicate ans_val(integer a, integer r, integer pi) = a == 2 * r * pi;
    predicate division_invariant(integer res, integer temp, integer ans, integer divisor) =
        res * divisor + temp == ans &&
        0 <= res && res <= ans / divisor &&
        0 <= temp && temp < divisor + ans;
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * r * 314 / 100;
    assigns \nothing;
*/
int func(int r)
{
    int pi;
    int ans;
    int res;
    int temp;
    int divisor;

    pi = 314;
    //@ assert pi_val(pi);

    //@ assert 2 * r * pi <= 2 * 100 * 314;
    ans = 2 * r * pi;
    //@ assert ans_val(ans, r, pi);

    res = 0;
    temp = ans;
    divisor = 100;
    //@ assert divisor_val(divisor);

    /*@
        loop invariant r_in_range(r);
        loop invariant pi_val(pi);
        loop invariant ans_val(ans, r, pi);
        loop invariant divisor_val(divisor);
        loop invariant division_invariant(res, temp, ans, divisor);
        loop assigns temp, res;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        res += 1;
    }

    //@ assert res * divisor + temp == ans;
    //@ assert temp < divisor;
    //@ assert res * 100 + temp == 2 * r * 314;
    //@ assert res == 2 * r * 314 / 100;

    return res;
}

int main()
{
    return 0;
}
