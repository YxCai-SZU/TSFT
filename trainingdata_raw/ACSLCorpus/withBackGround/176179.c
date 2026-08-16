/*@
    predicate valid_range(integer r) = 1 <= r <= 100;

    logic integer two_pi_approx(integer r) = 2 * 31415 * r;

    lemma two_pi_bound: \forall integer r; valid_range(r) ==> two_pi_approx(r) <= 2 * 31415 * 100;
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == (2 * 31415 * r) / 10000;
    assigns \nothing;
*/
long func(long r)
{
    // Variable declarations at top of scope
    long pi_approx;
    long two_pi_r;
    long result;
    long temp;

    pi_approx = 31415;

    //@ assert valid_range(r);
    //@ assert two_pi_approx(r) == 2 * pi_approx * r;
    //@ assert two_pi_approx(r) <= 2 * 31415 * 100;

    two_pi_r = 2 * pi_approx * r;
    result = 0;
    temp = two_pi_r;

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant two_pi_r == 2 * pi_approx * r;
        loop invariant result * 10000 + temp == two_pi_r;
        loop invariant result * 10000 + temp >= 0;
        loop invariant two_pi_r >= 0;
        loop invariant temp >= 0;
        loop assigns result, temp;
        loop variant temp;
    */
    while (temp >= 10000)
    {
        result += 1;
        temp -= 10000;
    }

    //@ assert result * 10000 + temp == two_pi_r;
    //@ assert temp < 10000;
    //@ assert result == (2 * 31415 * r) / 10000;

    return result;
}
