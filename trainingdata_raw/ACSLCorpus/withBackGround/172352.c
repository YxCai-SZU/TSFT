/*@
    predicate valid_range(integer r) = 1 <= r && r <= 100;
    
    logic integer scaled_r(integer r) = r * 100;
    
    logic integer total_product(integer r) = 2 * r * 314 * 100;
    
    lemma product_bounds: \forall integer r; valid_range(r) ==> 0 <= 2 * r * 314 <= 2 * 100 * 314;
*/

/*@
    requires valid_range(r);
    ensures \result == 2 * r * 314 / 100;
    assigns \nothing;
*/
long func(long r)
{
    long pi_approx;
    long scaled_r;
    long approx_circumference;
    long temp;
    long divisor;
    
    //@ assert valid_range(r);
    
    pi_approx = 314;
    scaled_r = r * 100;
    approx_circumference = 0;
    temp = 2 * scaled_r * pi_approx;
    divisor = 10000;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 314;
        loop invariant scaled_r == r * 100;
        loop invariant divisor == 10000;
        loop invariant 2 * scaled_r * pi_approx == 2 * r * 100 * 314;
        loop invariant approx_circumference * 10000 + temp == 2 * r * 314 * 100;
        loop invariant 0 <= approx_circumference * 100 <= 2 * r * 314;
        loop assigns temp, approx_circumference;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        approx_circumference += 1;
    }
    
    //@ assert approx_circumference * 10000 + temp == 2 * r * 314 * 100;
    
    return approx_circumference;
}

int main()
{
    return 0;
}
