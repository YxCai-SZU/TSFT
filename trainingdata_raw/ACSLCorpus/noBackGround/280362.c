/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == 2 * 3142 * r / 1000;
*/
long func(long r)
{
    long pi;
    long two;
    long one;
    long scale_factor;
    long numerator;
    long quotient;
    
    pi = 3142;
    two = 2;
    one = 1;
    scale_factor = 1000;
    numerator = two * pi * r;
    quotient = 0;
    
    /*@
        loop invariant ((1 <= ((r)) && ((r)) <= 100) &&
        (pi) == 3142 &&
        (two) == 2 &&
        (one) == 1 &&
        (scale_factor) == 1000 &&
        (numerator) >= 0 &&
        (quotient) * (scale_factor) + (numerator) == (two) * (pi) * (r));
        loop assigns numerator, quotient;
        loop variant ((numerator));
    */
    while (numerator >= scale_factor)
    {
        //@ assert numerator >= scale_factor && numerator >= 0;
        numerator -= scale_factor;
        quotient += one;
    }
    
    //@ assert quotient * scale_factor + numerator == two * pi * r;
    //@ assert numerator >= 0 && numerator < scale_factor;
    return quotient;
}
