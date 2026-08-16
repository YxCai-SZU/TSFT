/*@
    predicate is_valid_range(integer r) = 1 <= r && r <= 100;
    predicate scaled_r_eq(integer r, integer scaled) = scaled == r * 100;
    predicate pi_approx_eq(integer pi) = pi == 314;
    predicate temp_invariant(integer r, integer circ, integer temp) =
        circ * 10000 + temp == 2 * r * 314 * 100;
    predicate circ_bound(integer r, integer circ) = circ * 100 <= 2 * r * 314;
    logic integer final_result(integer r) = 2 * r * 314 / 100;
*/

/*@
    requires is_valid_range(r);
    ensures \result == final_result(r);
    assigns \nothing;
*/
long func(long r)
{
    long pi_approx;
    long scaled_r;
    long circumference;
    long temp;
    long divisor;

    //@ assert is_valid_range(r);
    pi_approx = 314;
    //@ assert pi_approx_eq(pi_approx);
    scaled_r = r * 100;
    //@ assert scaled_r_eq(r, scaled_r);
    circumference = 0;
    temp = 2 * scaled_r * pi_approx;
    divisor = 10000;

    /*@
        loop invariant is_valid_range(r);
        loop invariant pi_approx_eq(pi_approx);
        loop invariant scaled_r_eq(r, scaled_r);
        loop invariant temp_invariant(r, circumference, temp);
        loop invariant circ_bound(r, circumference);
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        circumference += 1;
    }

    //@ assert temp_invariant(r, circumference, temp);
    //@ assert temp < 10000;
    //@ assert circumference == final_result(r);
    return circumference;
}
