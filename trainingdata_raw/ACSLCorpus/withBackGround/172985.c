/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    logic integer pi_approx_const = 31416;
    logic integer divisor_const = 10000;
    logic integer calculate_circumference(integer r) = 2 * r * pi_approx_const;
    predicate loop_invariant(integer r, integer pi_approx, integer circumference, 
                             integer divisor, integer temp, integer count) =
        valid_range(r) &&
        pi_approx == pi_approx_const &&
        circumference == calculate_circumference(r) &&
        divisor == divisor_const &&
        circumference == temp + divisor * count &&
        count * divisor <= circumference;
*/

/*@
    requires valid_range(r);
    ensures \result == (2 * r * 31416) / 10000;
    assigns \nothing;
*/
int func(int r) {
    int pi_approx;
    int circumference;
    int result;
    int temp;
    int divisor;
    int count;
    
    //@ assert valid_range(r);
    pi_approx = 31416;
    circumference = 2 * r * pi_approx;
    
    result = 0;
    temp = circumference;
    divisor = 10000;
    count = 0;
    
    /*@
        loop invariant loop_invariant(r, pi_approx, circumference, divisor, temp, count);
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= divisor) {
        //@ assert circumference == temp + divisor * count;
        temp -= divisor;
        count += 1;
        //@ assert circumference == temp + divisor * count;
    }
    
    //@ assert circumference == divisor * count + temp && 0 <= temp < divisor;
    result = count;
    
    return result;
}
