/*@
    predicate scaled_r_invariant(integer r, integer pi_approx, integer divisor, integer scaled_r, integer result, integer remainder) =
        1 <= r <= 100 &&
        pi_approx == 3141592 &&
        divisor == 1000000 &&
        scaled_r == r * 2 * pi_approx &&
        result * divisor + remainder == scaled_r &&
        0 <= result &&
        0 <= remainder &&
        result <= r * 2 * 3141592 / 1000000;

    lemma loop_termination: \forall integer remainder, integer divisor; divisor > 0 ==> remainder >= divisor ==> remainder - divisor < remainder;
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * r * 3141592 / 1000000;
    assigns \nothing;
*/
long func(long r)
{
    long pi_approx;
    long scaled_r;
    long result;
    long remainder;
    long divisor;

    pi_approx = 3141592;
    divisor = 1000000;
    scaled_r = r * 2 * pi_approx;
    result = 0;
    remainder = scaled_r;

    /*@
        loop invariant scaled_r_invariant(r, pi_approx, divisor, scaled_r, result, remainder);
        loop invariant remainder >= 0;
        loop assigns remainder, result;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        remainder -= divisor;
        result += 1;
        //@ assert result * divisor + remainder == scaled_r;
    }

    //@ assert result * divisor + remainder == scaled_r;
    //@ assert result == 2 * r * 3141592 / 1000000;
    return result;
}
