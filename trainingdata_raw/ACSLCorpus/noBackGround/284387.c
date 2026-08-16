/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == ((2 * (r) * 314159) / 100000);
    assigns \nothing;
*/
long func(long r)
{
    long pi_approx;
    long two;
    long scale_factor;
    long result;
    long temp_r;

    pi_approx = 314159;
    two = 2;
    scale_factor = 100000;
    result = 0;
    temp_r = r * two * pi_approx;

    /*@
        loop invariant (1 <= (r) && (r) <= 100);
        loop invariant pi_approx == 314159;
        loop invariant two == 2;
        loop invariant scale_factor == 100000;
        loop invariant result * scale_factor + temp_r == ((r) * 2 * 314159);
        loop invariant result >= 0;
        loop invariant temp_r >= 0;
        loop assigns result, temp_r;
        loop variant temp_r;
    */
    while (temp_r >= scale_factor)
    {
        //@ assert result * scale_factor + temp_r == ((r) * 2 * 314159);
        result += 1;
        temp_r -= scale_factor;
    }

    //@ assert result == ((2 * (r) * 314159) / 100000);
    return result;
}
